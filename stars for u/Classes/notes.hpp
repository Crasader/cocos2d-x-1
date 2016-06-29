//
//  notes.hpp
//  MyCppGame
//
//  Created by zwj on 16/6/20.
//
//
//


/*
//亲密值：点错星星降低亲密值，亲密值会触发孩子相关行为  userDefualt- RELATION

//成长值： 通关增加孩子的成长值，影响孩子的成长，剧情的主线  userDef ualt- GROWTH
UserDefault::getInstance()->setIntegerForKey("GROWTH", growth);
//设置age
if (growth<=5)
{
    UserDefault::getInstance()->setIntegerForKey("age", 10);
    
}
else if (growth>5&&growth<10)
{
    UserDefault::getInstance()->setIntegerForKey("age", 15);
    
}
else if (growth>10&&growth<15)
{
    UserDefault::getInstance()->setIntegerForKey("age", 20);
    
}

 8?


//增加 夜空旋转？

//LIST .PLIST:

/*//获取的星座
item0: 白羊   case 1
item1: 金牛    case 2
2:双子    case 3
3:双鱼
4:摩羯
5:处女
6:射手
7:水平
8:天枰
9:狮子
10:天蝎
11: 巨蟹
*/