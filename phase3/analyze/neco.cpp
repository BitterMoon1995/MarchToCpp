///*
// * 用DCP分析类内存布局，看一下虚继承是个啥情况，命令：
// *
// * cl neco.cpp /d1reportSingleClassLayoutKatzlane
// *
// * 验证确实可行，注意和老师教的（错的）有出入，是总书记亲自搜索，亲自百度找到的。
// * 最好加个主函数，不然报fatal error LNK1561: 必须定义入口点，不好看。
// */
//class Animal{
//public:
//    int age;
//};
//
//class Cat:virtual public Animal{
//};
//
//class Human:virtual public Animal{
//
//};
//
//class Katzlane: public Human, public Cat{
//
//};
//
//int main(){
//    return 0;
//}