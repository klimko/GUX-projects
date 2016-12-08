#ifndef NEWGAMEDIALOG_H
#define NEWGAMEDIALOG_H

#include <QObject>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QSpacerItem>

#include <QDebug>

class NewGameDialog: public QDialog
{
    Q_OBJECT

public:
    NewGameDialog();

private:
    QVBoxLayout *m_main_lt;

    QHBoxLayout *m_players_lt;
    QHBoxLayout *m_theme_lt;
    QHBoxLayout *m_size_lt;
    QHBoxLayout *m_btns_lt;

    QLabel *m_players_lbl;
    QLabel *m_theme_lbl;
    QLabel *m_size_lbl;

    QPushButton *m_create_btn;
    QPushButton *m_cancel_btn;

    QSpacerItem *m_btns_spacer;

    QComboBox *m_players_cb;
    QComboBox *m_theme_cb;
    QComboBox *m_size_cb;

    void populateComboBoxes();

private slots:
    void onCreateClicked();

signals:
    void passSettings(int, int, int);
};

#endif // NEWGAMEDIALOG_H
