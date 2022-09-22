#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_IssuePannel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class IssuePannelClass; };
QT_END_NAMESPACE

class IssuePannel : public QMainWindow
{
    Q_OBJECT

public:
    IssuePannel(QWidget *parent = nullptr);
    ~IssuePannel();

private:
    Ui::IssuePannelClass *ui;
};
