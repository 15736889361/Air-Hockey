#include "SmartRes.h"

USING_NS_CC;

SmartRes* SmartRes::_instancce = nullptr;

SmartRes* SmartRes::getInstance()
{
    if (!_instancce)
    {
        _instancce = new SmartRes();
        _instancce->init();
    }
    return _instancce;
}

bool SmartRes::init(void)
{
    return true;
}

void SmartRes::setVirtualScreenValue(int dir, float value)
{
    if (dir == SMART_RES_FIXED_HEIGHT)
    {
        const Size& winSizeInPixels = Director::getInstance()->getWinSizeInPixels();
        
        m_scale = winSizeInPixels.width / value;
        m_screenSize.width = value;
        m_screenSize.height = winSizeInPixels.height / m_scale;

		Director::getInstance()->getOpenGLView()->setDesignResolutionSize(m_screenSize.width, m_screenSize.height, ResolutionPolicy::NO_BORDER);

        log("Virtual width: %0.2f, Virtual height: %0.2f, scale: %0.2f",
              m_screenSize.width, m_screenSize.height, m_scale);
        
        const Size& winSize = Director::getInstance()->getWinSize();
        m_center.x = winSize.width / 2;
        m_center.y = winSize.height / 2;
        m_left = 0;
        m_right = m_screenSize.width - 1;
        m_top = m_screenSize.height - 1;
        m_bottom = 0;
    }
    else
    {
        
    }
}

void SmartRes::setVirtualScreenWidth(float width)
{
    const Size& winSizeInPixels = Director::getInstance()->getWinSizeInPixels();
    log("getWinSizeInPixels width: %0.2f, height: %0.2f",
          winSizeInPixels.width, winSizeInPixels.height);
    
    float factor1 = Director::getInstance()->getContentScaleFactor();
    log("getContentScaleFactor1 = %0.2f", factor1);
    
    const Size& winSize_pre = Director::getInstance()->getWinSize();
    log("getWinSize Pre width: %0.2f, height: %0.2f",
          winSize_pre.width, winSize_pre.height);
    
    
    m_scale = winSizeInPixels.width / width;
    m_screenSize.width = width;
    m_screenSize.height = winSizeInPixels.height / m_scale;
	Director::getInstance()->getOpenGLView()->setDesignResolutionSize(m_screenSize.width, m_screenSize.height, ResolutionPolicy::NO_BORDER);

    log("Virtual width: %0.2f, Virtual height: %0.2f, scale: %0.2f",
        m_screenSize.width, m_screenSize.height, m_scale);
    
    const Size& winSizeInPixels2 = Director::getInstance()->getWinSizeInPixels();
    log("getWinSizeInPixels2 width: %0.2f, height: %0.2f",
          winSizeInPixels2.width, winSizeInPixels2.height);
    
    float factor2 = Director::getInstance()->getContentScaleFactor();
    log("getContentScaleFactor2 = %0.2f", factor2);

    const Size& winSize = Director::getInstance()->getWinSize();
    log("getWinSize Aft width: %0.2f, height: %0.2f",
          winSize.width, winSize.height);
    
    m_center.x = winSize.width / 2;
    m_center.y = winSize.height / 2;
    m_left = 0;
    m_right = m_screenSize.width - 1;
    m_top = m_screenSize.height - 1;
    m_bottom = 0;

    log("center x: %0.2f, center y: %0.2f", m_center.x, m_center.y);
    log("top: %0.2f, right: %0.2f, bottom: %0.2f, left: %0.2f", m_top, m_right, m_bottom, m_left);
}

void SmartRes::setVirtualScreenHeight(float height)
{
	const Size& winSizeInPixels = Director::getInstance()->getWinSizeInPixels();
	log("getWinSizeInPixels width: %0.2f, height: %0.2f",
		winSizeInPixels.width, winSizeInPixels.height);

	float factor1 = Director::getInstance()->getContentScaleFactor();
	log("getContentScaleFactor1 = %0.2f", factor1);

	const Size& winSize_pre = Director::getInstance()->getWinSize();
	log("getWinSize Pre width: %0.2f, height: %0.2f",
		winSize_pre.width, winSize_pre.height);


	m_scale = winSizeInPixels.height / height;

	m_screenSize.width = winSizeInPixels.width / m_scale;
	m_screenSize.height = height;
	Director::getInstance()->getOpenGLView()->setDesignResolutionSize(m_screenSize.width, m_screenSize.height, ResolutionPolicy::NO_BORDER);

	log("Virtual width: %0.2f, Virtual height: %0.2f, scale: %0.2f",
		m_screenSize.width, m_screenSize.height, m_scale);

	const Size& winSizeInPixels2 = Director::getInstance()->getWinSizeInPixels();
	log("getWinSizeInPixels2 width: %0.2f, height: %0.2f",
		winSizeInPixels2.width, winSizeInPixels2.height);

	float factor2 = Director::getInstance()->getContentScaleFactor();
	log("getContentScaleFactor2 = %0.2f", factor2);

	const Size& winSize = Director::getInstance()->getWinSize();
	log("getWinSize Aft width: %0.2f, height: %0.2f",
		winSize.width, winSize.height);

	m_center.x = winSize.width / 2;
	m_center.y = winSize.height / 2;
	m_left = 0;
	m_right = m_screenSize.width - 1;
	m_top = m_screenSize.height - 1;
	m_bottom = 0;

	log("center x: %0.2f, center y: %0.2f", m_center.x, m_center.y);
	log("top: %0.2f, right: %0.2f, bottom: %0.2f, left: %0.2f", m_top, m_right, m_bottom, m_left);
}

void SmartRes::setVirtualWinWidth(Size size)
{
	m_winSize = size;
}
