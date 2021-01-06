#include "keyboard.h"

keyBoard::keyBoard(QWidget *parent) :
    QWidget(parent)
{
    this->InitWindow();
    this->InitForm();

    QDesktopWidget* w = QApplication::desktop();
    deskWidth = w->screenGeometry().width();
    deskHeight = w->screenGeometry().height();
    frmWidth = this->width();
    frmHeight = this->height();
}
void keyBoard::InitWindow()
{
    this->setProperty("Form", true);
    this->setWindowFlags(Qt::Tool | Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    this->setFixedSize(14 * BTN_SIZE, 3 * BTN_SIZE);
    this->setFocusPolicy(Qt::NoFocus);

    keyWindow = new QStackedWidget(this);
    keyWindow->setFixedSize(13 * BTN_SIZE, 2 * BTN_SIZE);
    letterWindow = new QWidget;
    signWindow = new QWidget;

    // 填加功能按钮
    closeBtn = new QPushButton(this);
    closeBtn->setObjectName("closeBtn");
    closeBtn->setProperty("function", true);
    closeBtn->setText(tr("X"));
    closeBtn->setFixedSize(BTN_SIZE, BTN_SIZE);

    // 删除一个字符
    delBtn = new QPushButton(this);
    delBtn->setObjectName("delBtn");
    delBtn->setProperty("function", true);
    delBtn->setText(tr("D"));
    delBtn->setFixedSize(BTN_SIZE, BTN_SIZE);

    // 改变输法类型:大写,小写,字符
    typeBtn = new QPushButton(this);
    typeBtn->setObjectName("typeBtn");
    typeBtn->setProperty("function", true);
    typeBtn->setText(tr("小"));
    typeBtn->setFixedSize(BTN_SIZE, BTN_SIZE);

    // 换肤
    styleBtn = new QPushButton(this);
    styleBtn->setObjectName("styleBtn");
    styleBtn->setProperty("function", true);
    styleBtn->setText(tr("style"));
    styleBtn->setFixedSize(BTN_SIZE, BTN_SIZE);

    // 填加数字键盘
    btn1 = new QPushButton(this);
    btn1->setText(tr("1"));
    btn1->setProperty("num", true);
    btn1->setFixedSize(BTN_SIZE, BTN_SIZE);


    layout->addWidget(delBtn,   0,11,1,1);
    layout->addWidget(closeBtn, 0,12,1,1);
    layout->addWidget(typeBtn,  1,13,1,1);
    layout->addWidget(styleBtn, 2,13,1,1);
    layout->addWidget(keyWindow,1,0,2,13);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    this->setLayout(layout);
}
void keyBoard::InitForm()
{
    currentStyle = 0;
    currentLineEdit = 0;
    mousePressed = false;
    currentType = "min";
    changeType("min");
    currentStyle = 0;
    changeStyle(currentStyle);

    QList<QPushButton *> btn = this->findChildren<QPushButton *>();
    foreach (QPushButton * b, btn) {
        connect(b, SIGNAL(clicked()), this, SLOT(slotBtnClicked()));
    }

    // 绑定全局改变焦点信号槽
    connect(qApp, SIGNAL(focusChanged(QWidget *, QWidget *)),
            this, SLOT(focusChanged(QWidget *, QWidget *)));
}
void keyBoard::focusChanged(QWidget *, QWidget *nowWidget)
{
    if (nowWidget != 0 && !this->isAncestorOf(nowWidget))
    {
        if (nowWidget->inherits("QLineEdit"))
        {
            currentLineEdit = (QLineEdit *)nowWidget;

            QPoint movePoint;

            // 鼠标点击位置坐标
            if (QCursor::pos().y() > deskHeight / 2)
            {
                // 靠上居中显示
                movePoint = QPoint(deskWidth/2 - frmWidth/2, 0);
            }
            else
            {
                // 靠下居中显示
                movePoint = QPoint(deskWidth/2 - frmWidth/2, deskHeight - frmHeight);
            }

            this->move(movePoint);
            this->repaint();
            this->setVisible(true);
        }
        else
        {
            currentLineEdit = 0;
            //qDebug() << "BBB";
            this->setVisible(false);
            // 需要将输入法切换到最初的原始状态--小写
            currentType="min";
            changeType(currentType);
            currentStyle = 0;
            changeStyle(currentStyle);
            keyWindow->setCurrentIndex(0);
        }
    }
}
void keyBoard::slotBtnClicked()
{
    QPushButton *btn = (QPushButton *)sender();
    QString objectName = btn->objectName();

    if (objectName == "typeBtn")
    {
        if (currentType == "min")
        {
            currentType = "max";
        }
        else if (currentType == "max")
        {
            currentType = "sign";
        }
        else
        {
            currentType = "min";
        }
        changeType(currentType);
    }
    else if (objectName == "delBtn")

    else
    {
        QString value = btn->text();
        // 如果是&按钮，因为对应&被过滤,所以真实的text为去除前面一个&字符
        if (value == "&&")
        {
            value = value.right(1);
        }
        // 当前不是中文模式,则单击按钮对应text为传递参数
        if (currentType != "chinese")
        {
            if (currentLineEdit != 0)
            {
                currentLineEdit->insert(value);
            }
        }
    }
}
