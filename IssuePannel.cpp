#include "IssuePannel.h"

IssuePannel::IssuePannel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IssuePannelClass())
{
    ui->setupUi(this);
}

IssuePannel::~IssuePannel()
{
    delete ui;
}
