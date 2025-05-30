///////////////////
/// \author JackeyLea
/// \date 2024-10-31
/// \note 界面显示类
///////////////////

#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QTimer>

#include "dataparser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    /// 构造函数
    /// \brief MainWidget
    /// \param parent
    ///
    explicit MainWidget(QWidget *parent = nullptr);

    ///
    /// 释放资源
    ~MainWidget();

protected:
    /// 初始化信号槽
    /// \brief initConn
    ///
    void initConn();

private slots:

    /// 串口按钮响应
    /// \brief sltBtnCOM
    ///
    void sltBtnCOM();

    /// 仿真数据按钮响应
    /// \brief sltBtnSIM
    ///
    void sltBtnSIM();

    /// 打开本地文件按钮响应
    /// \brief sltBtnLocal
    ///
    void sltBtnLocal();

    /// 播放按钮响应
    /// \brief sltBtnPlay
    ///
    void sltBtnPlay();

    /// 暂停按钮响应
    /// \brief sltBtnPause
    ///
    void sltBtnPause();

    /// 清空按钮响应 清空界面数据和缓存区数据
    /// \brief sltBtnClear
    ///
    void sltBtnClear();

    /// 保存按钮响应 保存串口收到的数据
    /// \brief sltBtnSave
    ///
    void sltBtnSave();

    /// 定时刷新界面
    /// \brief sltUpdateWidget
    ///
    void sltUpdateWidget(_eegPkt pkt);

private:
    Ui::MainWidget *ui;

    // 解析器
    DataParser *m_pParser;

    bool m_bStatus;//状态控制

    DataSourceType m_eType;//当前模式

    //计时
    uint m_unSec,m_unMinute,m_unHour,m_unDay,m_unYear;
};
#endif // MAINWIDGET_H
