#ifndef  _APP_DELEGATE_H_
#define  _APP_DELEGATE_H_

#include "cocos2d.h"

class MenuScene;

class  AppDelegate : private cocos2d::Application
{
public:
    AppDelegate();
    virtual ~AppDelegate();

    virtual void initGLContextAttrs();
    virtual bool applicationDidFinishLaunching();
    virtual void applicationDidEnterBackground();
    virtual void applicationWillEnterForeground();

private:
    void initOpenGL();
    void initMultiResolution();
    void initDirector();
    void initSpriteCache();
    void createAndRunScene();
};

#endif // _APP_DELEGATE_H_

