#include "infowidget.h"
#include "ui_infowidget.h"
#include <QSqlRecord>
#include <QTextDocument>

InfoWidget::InfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoWidget)
{
    ui->setupUi(this);
    editedText = "<html><body>";
}

InfoWidget::~InfoWidget()
{
    delete ui;
}

void InfoWidget::createInfo(QString name)
{
    model = new QSqlQueryModel;
    QString select = "select * from raceInfo where name = 'Dwarf'";
    //select.arg(name);
    model->setQuery(select);

    for (int i=1; i<=10; i++) {
        QString text = model->record(0).value(i).toString();
        if (i == 1) {
            text = "<h1>" + text + "</h1>";
            editedText += text;
        } else {
            editedText += text + "<br><br>";
        }
    }

    int count = 0;
    bool wasEm = false;
    for (auto c : editedText) {
        if (c == "*") {
            if (editedText.at(count+1).toCaseFolded() == "_") {
                editedText.replace(count, 2, "<b>");
            } else if (!wasEm) {
                editedText.replace(count, 1, "<i>");
                wasEm = true;
            } else if (wasEm) {
                editedText.replace(count, 1, "</i>");
                wasEm = false;
            }
        }

        if (c == "_")
            editedText.replace(count, 2, "</b>");

        count++;
    }
    editedText.remove("#");

    editedText.append("</body></html>");

    setInfo();
}

void InfoWidget::setInfo()
{
    ui->label->setText(editedText);
}
