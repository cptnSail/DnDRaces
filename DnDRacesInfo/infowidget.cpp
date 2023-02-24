#include "infowidget.h"
#include "ui_infowidget.h"
#include <QSqlRecord>
#include <QLayout>

InfoWidget::InfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoWidget)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);

    editedText = "<html><body>";
}

InfoWidget::~InfoWidget()
{
    delete ui;
}

void InfoWidget::createInfo(QString name)
{
    model = new QSqlQueryModel;
    subModel = new QSqlQueryModel;

    QString select = "select * from raceInfo where name = '%1'";
    model->setQuery(select.arg(name));
    editText(model);
    editedText.append("<br><br>");

    if (model->record(0).value("subrace").toInt() != 0) {
        select = "select * from subraces "
                 "join raceInfo on raceInfo.subrace = subraces.id "
                 "where raceInfo.name = '%1'";
        subModel->setQuery(select.arg(name));
        editText(subModel, true);
    }

    editedText.append("</body></html>");
    setInfo();

    delete model;
    delete subModel;
}

void InfoWidget::setInfo()
{
    ui->textEdit->clear();
    ui->textEdit->setText(editedText);
}

void InfoWidget::editText(QSqlQueryModel *model, bool subrace)
{
    editedText += editTitle(model->record(0).value("name").toString());

    if (!subrace) {
        editedText += editTraitsTitle(model->record(0).value("desc").toString());

        QString base = "";
        for (int i = 3; i <= 9; i++) {
            base += model->record(0).value(i).toString();
        }
        editedText += editBaseInfo(base);
    } else {
        QString desc = model->record(0).value("desc").toString() + model->record(0).value("asi_desc").toString();
        editedText += editSubDesc(desc);
    }

    editedText += editTraits(model->record(0).value("traits").toString());

    editedText.remove("##");
}

QString InfoWidget::editTitle(QString text)
{
    return text = "<h1>" + text + "</h1>";
}

QString InfoWidget::editTraitsTitle(QString text)
{
    text = "<h2>" + text;

    int i = text.indexOf("Traits");
    text.insert(i+6, "</h2>");

    return text;
}

QString InfoWidget::editSubDesc(QString text)
{
    text.remove("Rock Gnome");

    text.replace("**_", "<br><br><i><b>");
    text.replace("_**", "</b></i>");

    return text;
}

QString InfoWidget::editBaseInfo(QString text)
{
    text.replace("**_", "<br><br><i><b>");
    text.replace("_**", "</b></i>");

    return text;
}

QString InfoWidget::editTraits(QString text)
{
    text.replace("**_", "<br><br><i><b>");
    text.replace("_**", "</b></i>");

    text.remove("* _");
    text.remove("_");

    bool wasI = false;
    int count = 0;
    for (auto a : text) {
        if (a == '*' && wasI == false) {
            text.replace(count, 1, "<i>");
            wasI = true;
        } else if (a == '*') {
            text.replace(count, 1, "</i>");
            wasI = false;
        }

        count++;
    }

    if (text.indexOf("Tinker") > 0)
        text = tinkerFix(text);

    return text;
}

QString InfoWidget::tinkerFix(QString text)
{
    text.replace("Clockwork Toy.", "<ul><li>Clockwork Toy.");
    text.replace("Fire Starter.", "</li><li>Fire Starter.");
    text.replace("Music Box.", "</li><li>Music Box.");
    text.append("</li></ul>");

    return text;
}


