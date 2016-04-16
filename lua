local label=CCLableTTF:create(“nihao”,”Courier”,50)   //Courier:字体， 50：字号
label:setPosition(cpp(300,300))     //位置
local scene=CCScene:create()        //创建场景
local layer=CCLayer:create()    	//创建层

scene:addChild(layer)    //把层添加到场景
layer:addChild(label)		//把label添加到层

CCDirector:sharedDirector():runWithScene(scene)  	//把场景通过导演来执行