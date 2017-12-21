/**
 * @file
 * @brief   视频解码线程
 * @author  itisyang
 * @date    20171221
 * @note
 */

#ifndef VIDEOCTL_H
#define VIDEOCTL_H

#include <QObject>
#include <QThread>

#include "globalhelper.h"

#include "SDL.h"
#include "SDL_thread.h"

#include "readfile.h"
#include "videodec.h"
#include "audiodec.h"
#include "subtitledec.h"
#include "videodataoprator.h"

//单例模式
class VideoCtl : public QObject
{
    Q_OBJECT

public:
    //explicit VideoCtl(QObject *parent = nullptr);

    static VideoCtl* GetInstance();
    static void ReleaseInstance();

    bool StartPlay(QString strFileName);//开始播放

signals:
    void SigStartDec(); //开始解码信号
public slots:
    void OnPlayMsg(QString strMsg);
private:
    explicit VideoCtl(QObject *parent = nullptr);

    bool Init();

    bool ConnectSignalSlots();

public:
    AVFormatContext *ic;

private:

    static VideoCtl* m_pInstance;

    bool m_bInited;

    ReadFile m_ReadFile;//文件读取

    VideoDataOprator m_Oprator;//数据处理

    VideoDec m_VideoDec;//视频解码
    AudioDec m_AudioDec;//音频解码
    SubtitleDec m_SubtitleDec;//字幕解码

    static const QString strProgrameBirthYear;//程序初始创建年
};

#endif // VIDEOCTL_H