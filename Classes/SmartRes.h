#ifndef __SMART_RES_H_
#define __SMART_RES_H_


#include "cocos2d.h"

USING_NS_CC;

#define SMART_RES_FIXED_HEIGHT 0
#define SMART_RES_FIXED_WIDTH 1
#define _s_center     SmartRes::getInstance()->getCenter()
#define _s_top        SmartRes::getInstance()->getTop()
#define _s_right      SmartRes::getInstance()->getRight()
#define _s_bottom     SmartRes::getInstance()->getBottom()
#define _s_left       SmartRes::getInstance()->getLeft()
#define _s_scale      SmartRes::getInstance()->getScale()
#define _s_xy(v)      SmartRes::getInstance()->xy(v)
#define _s_height     SmartRes::getInstance()->getScreenHeight()
#define _s_width      SmartRes::getInstance()->getScreenWidth()
#define _s_winsize    SmartRes::getInstance()->getScreenSize()
#define _s_wsize      SmartRes::getInstance()->getWinSize()

class SmartRes
{
public:
    static SmartRes* getInstance();

    void setVirtualScreenWidth(float width);
    void setVirtualScreenHeight(float height);
    void setVirtualScreenValue(int dir, float value);
	void setVirtualWinWidth(Size size);

    const Size getScreenSize(void)
    {
        return m_screenSize;
    }

    const float getScreenHeight(void)
    {
        return m_screenSize.height;
    }

    const float getScreenWidth(void)
    {
        return m_screenSize.width;
    }

    float getScale(void)
    {
        return m_scale;
    }

    const Vec2 getCenter(void)
    {
        return m_center;
    }

    float getTop(void)
    {
        return m_top;
    }

    float getRight(void)
    {
        return m_right;
    }

    float getBottom(void)
    {
        return m_bottom;
    }

    float getLeft(void)
    {
        return m_left;
    }

    float xy(float v)
    {
        return m_scale * v;
    }

    const Size getWinSize(void)
    {
        return m_winSize;
    }

private:
    SmartRes(void)
        : m_scale(1.0f)
        , m_top(0)
        , m_right(0)
        , m_bottom(0)
        , m_left(0)
    {
    }
    bool init(void);

    static SmartRes* _instancce;

    Size m_screenSize;
    Vec2 m_center;
    float m_scale;
    float m_top;
    float m_right;
    float m_bottom;
    float m_left;

    Size m_winSize;
};

#endif