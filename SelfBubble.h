#ifndef SELFBUBBLE_H
#define SELFBUBBLE_H

#include <QWidget>

namespace Ui {
class SelfBubble;
}

class SelfBubble : public QWidget
{
    Q_OBJECT

public:
    explicit SelfBubble(QWidget *parent = nullptr);
    ~SelfBubble();

    void setLogo(QIcon icon);
    void setIdent(QString id);
    void setName(QString name);
    void setMessage(QString msg);

private:
    Ui::SelfBubble *ui;
};

#endif // SELFBUBBLE_H
