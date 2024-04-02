
> [!NOTE] Title
> Contents
# STL（标准模板库）：
## 特性
1. 数据结构与算法分离，使STL非常通用，如sort()可以操作任何数据集合，包括链表、容器与数组
2. 非面向对象，依赖于模板
3. 组件主要包括容器、迭代器、算法等，容器是管理某类对象的集合，迭代器用于在对象集合上的遍历，算法用于处理集合内的元素
4. 存在于std命名空间中




## string
1. +=  //字符串相加
2. ==   !=   < <=  > >= //比较大小
3. s.length() /  s.size()  //字符串长度
4. s.find(str) //s里找str,返回第一次匹配的位置, 没有则返回-1；
5. s.find(str, pos) // 从pos位置开始找，没有返回-1；
6. s.substr(pos, len) //返回从pos位置开始长度为len的字符串
7. s.substr(pos) //返回从pos位置后到结尾的字符串
8. s.replace(pos, len, str) //将s从pos位置长度为len的字符串替换为str
9. s.clear() //清空
10. s.insert(pos, str) //在pos位置插入字符串str
11. s,erase(first, last) //从first到last删除
```c++
//基础示范
int main(){
	//string初始化
	string s1;//默认初始化，空字符串
	string s2 = s1;//s2是s1的副本
	string s3 = "abcd"；//s3初始化为"abcd"
	string s4(4, 'c');//s4初始化为"cccc"
	//string的读写
	cin>>s1>>s2; //最基础的读入，遇到空格与回车停止
	cout<<s1<<s2<<endl; //依次输出
	getline(cin, s1); //读入一整行，包括空格，遇到回车暂停
	//char s[]的读入
	char s[20];
	cin.getline(s, 20);//代替被禁用的gets()函数
	//string的printf()输出
	string s;
	printf("%s",s.c_str());//使用printf()必须先转化为字符数组
}
//用法
int main(){
	//string 加法
	string s1 = "aaa", s2 = "bbb", s3;
	s1 += a; //s1的末尾加上字符s
	s1 += s2;//s1的末尾加上字符串s2\
	s3 = "aaa" + s1 + s2 + 'a'//按顺序拼接
	//string的empty, length, size
	string S, s2 = "abc";//S为空，s2为"abc"
	cout<<S.empty()<<endl;//结果为1，表示s1为空
	cout<<s2.empty()<<endl;//结果为0，表示s2非空
	cout<<s2.size()<<endl; //结果为3，表示s2中有3个元素
	cout<<s2.length()<<endl;//结果与size一致
	//访问string中的元素
	string s = "hello, wolld";
	for(int i = 0;i < s.size();i++){
		cout<<s[i]<<endl;//可以直接将string当作字符数组进行访问
	}
	//s.find(str)在s里寻找str,返回第一次成功匹配的位置，没有则返回-1
	s = "aaabbb";
	string str = "bbb";
	cout<<s,find("abc")<<endl;//返回-1.未找到
	cout<<s.find(str)<<endl;  //返回/3, 即找到的第一个str串首字符下标为3
	//s.find(str, pos)从字符串s的pos位置开始查找str
	cout<<s.find("aaa", 1)//返回-1, 无法找到
	//s.substr(pos, len) //返回从pos位置开始长度为len的字符串以及s.substr(pos) 返回从pos位置后到结尾的字符串
	s1 = s.substr(3);//则s1为"bbb"
	s2 = s.substr(0, 3);//s2为"aaa"
	//s.replace(pos, len, str) //将s从pos位置长度为len的字符串替换为str
	s.replace(0, 3, str);//s为"bbbbbb"
	//s.clear()清空
	s.clear();//s变为空字符串
	s = "aaaccc", str = "bbb";
	//string插入
	s.insert(3, str);//s变为"aaabbbccc"
	//固定位置、固定长度删除
	s = "abcdef", str = "abcdef";
	s.erase(3);//s变为"abc"
	str.erase(3, 2);//str变为"abcf"
	//字符串数组
	string ST[100];
	int n;
	cin>>n;
	getchar();//将n后面的回车读入
	for(int i = 1;i<=n;i++){
		getline(cin, s[i]);
	}
	//int与string的转换
	s = "123";
	int n = stoi(s);
	printf("%d",n);//123
	int m = 24;
	string t = to_string(m);//使用需在c++11的标准下进行
	
}
```
## 栈
### 特性
管理数据的结构，体现”先进后出“的特性，一般不允许访问中间元素

### 基本操作
```c++
#include <stack>
using namespace std;
int main(){
	stack<int> s;
	s.push(1);//入栈
	s.pop();//弹出
	int stacktop = s.top();//取栈首
	bool isempty = s.empty();//栈是否为空
	int stacksize = s.size();//栈内元素数量
}
```
![[栈.png]]
## 队列
### 特性
体现数据“先进先出”的特性，插入在队尾，删除在队首
```c++
#include <queue>
using namespace std;
queue<int> q;
q.push();//入队
q.pop();//弹出
int qfront = q.front();//取队首
int qback = q.back();//取队尾
bool isempty = q.empty();//队为空的判断
int qsize = q.size();    //队内元素数量
//大顶堆
priority_queue<int> p;//默认大顶堆，先输出大数据
priority_queue<int, vector<int>, greater<int> >q;//小顶堆，先输出小数据
//可以考虑重载运算符后使用大顶堆和小顶堆
```
### 双端队列
1. deque和vector类似，但在deque两端添加或删除元素开销很小，随机访问性能不如vector， 插入删除不如list，如果不需要从头部插入和删除数据，一般使用vector
2. 不要对deque使用迭代器，因为：
	1. C ++迭代器用于对数据结构中的元素进行顺序访问或随机访问。因此，对于根据定义不允许顺序或随机访问的数据结构，迭代器没有任何意义。这就是栈和队列没有迭代器的原因。另一方面，向量和列表允许对元素进行顺序和/或随机访问，因此迭代器对于这些数据结构是有意义的。
	2. 栈是后进先出数据结构。在任何给定时间只能访问栈的顶部元素。根据定义，永远不会顺序遍历栈的元素，也不会使用随机访问来获取栈中的特定元素。因此，栈没有迭代器。
	3. 队列是先进先出数据结构。在任何给定时间，您只能在一端（尾部）放置元素，并从另一端（头部）检索元素。根据定义，您永远不会顺序遍历队列的元素，也不会使用随机访问来获取队列中的特定元素。
```c++
#include <deque>
using nameapace std;
d[i];//返回d中下标为i的元素的引用
d.front();//返回第一个元素的引用
d.back();//返回最后一个元素的引用
d.pop_back();//删除尾部元素，无返回值
d.pop_front();//删除头部元素，无返回值
d.push_back(e);//在尾部添加一个元素e的副本
d.push_front(e);//在头部添加一个元素e的副本
```





## 向量vector
### 特性
向量(vector)是一个封装了动态大小的顺序容器
### 操作
```c++
#include <vector>
vector<int> v;
v.push_back(1);//向量尾部增加元素
ite.insert(1);//向量的迭代器前面增加一个元素
v.erase(iterator ite);//删除迭代器指向的元素
v.pop_back();//删除向量的最后一个元素
v.clear();//情空向量
v.size();//返回向量的元素个数
v.empty();//判断向量为空
v.front();//返回首元素引用
v.back();//返回尾元素引用
v.begin();//头元素指针
v.end();//尾元素指针,指向最后一个元素的下一个元素
```

## 映射map
### 特性
映射(map)是关联容器，按照特定顺序存储由键值和映射值的组合形成的元素
### 操作
```c++
#include <map>
map<char, int>m;
m['a'] = 11;
m['b'] = 12;
cout<<m['a']<<endl;//将输出11；
map<char, int>::iterator ite;//建立迭代器
for(ite = m.begin(); ite != m.end();ite++){
	cout<<ite->first<<" "<<ite->second<<endl;//输出m中的键值及相应映射值
}
ite = m.find('b');//如果能找到这一键值，返回其引用
cout<<ite->first<<" "<<ite->second<<endl;
if(m.find('c') == m.end()){
	cout<<"yes"<<endl;
}//map.find()找不到就返回尾指针的引用，注意尾指针指向的不是最后一组pair,而是下一组
m.erase('a');//去掉a及其对应的映射值
m.count('b');//返回map中键为b的数目，但对于map来讲，只有0或1
```
## 集合set
### 特性
是按照特定顺序存储唯一元素的容器，可以自动排序(从小到大)和去重
### 操作
```c++
#include <set>
using namespace std;

set<int, less<int> >s;//内部升序排列，可以写作set<int, less >s
set<int, greater<int> >s;//内部降序排列，可以写作set<int, greater >s
//若逗号后什么都不加，则默认升序
s.count(10);//返回s中值为10的具体数目，但对于set只有0或1两种可能
s.empty();//判断集合是否为空
s.size();//返回集合元素数量
s.insert(e);//把e插入到set中
s.insert(begin, end);//将区间[begin, end)中的值插入到set中
s.erase(e);//将e删除
s.erase(pos);//将pos处的元素删除
s.erase(begin, end);//将[begin, end)内的元素删除
s.begin();//返回首元素的引用
s.end();//返回尾元素的后一个的引用
s.find(m);//从[set容器]中查找值为m的元素O(log n);若存在，返回一个迭代器，指向键值x;若不存在，返回一个迭代器，指向set.end()。
//使用迭代器进行循环遍历
for(set<int>::iterater it = st.begin(); it != st.end();it++)
```

## 表list
### 特性
使用双向链表管理元素，不支持随机存取，也不能使用"[]"运算符，但是元素的插入和删除很快
### 操作
```c++
#include <list>
list<int> l;
//元素存取
l.front();//返回第一个元素，不检查是否存在
l.back();//返回最后一个元素，不检查是否存在
//插入元素
l.insert(pos, e);//在pos位置插入元素e的副本，并返回新元素位置
l.insert(pos, n, e);//在pos位置插入n个元素e的副本
l.push_back(e);//在尾部添加一个元素e的副本
l.push_front(e);//在头部添加一个元素e的副本
//移除元素
l.pop_back();//移除最后一个元素，无返回值
l.pop_front();//移除第一个元素，没有返回值
l.erase(pos);//删除pos位置的元素，返回下一个元素的位置
l.erase(begin, end);//删除区间[begin,end)内所有元素，返回下一个元素的位置
l.remove(val);//移除所有值为val的元素
l.remove_if(op);//移除所有满足“op(val)==true”的元素
l.clear();//移除所有元素，
l.resize(num);//将元素数量改为num,增加元素从默认构造函数产生，多余的元素被删除
l.resize(num, e);//将元素数量改为num,增加的元素是e的副本
//移除操作
l.unique();//移除重复元素
l.unique(op);//移除所有满足“op(val)==true”的重复元素
l1.splice(pos, l2);//将l2的所有元素转移到l1的迭代器之前
l1.splice(pos, l2, l2pos);//将l2内l2pos所指元素转移到l1的迭代器之前
l1.splice(pos, l2, l2begin, l2end);//将l2内对应区间所有元素转移到l1的pos之前
l.sort();//按升序排序
l1.merge(l2);//假设l1和l2已排序，将l2全部元素转移到l1并且仍保证为有序表
l.reverse();//将所有元素反序
```




## 迭代器
### 特性
可以理解为对容器元素的一个指针，需要重载* 运算符
### 类别
1. 正向迭代器：
		容器类名::iterator 迭代器名
2. 常量正向迭代器
		容器类名::const_iterator 迭代器名
3. 反向迭代器
		容器类名::reverse_iterator 迭代器名
4. 常量反向迭代器
		容器类名::const_reverse_iterator 迭代器名
### 基于运算类型的迭代器分类
所有迭代器都支持解引用运算符（ * ）和自增运算符（++）
Input iterator 在此基础上支持 = =，！=，单次读取，->;
Output Iterator仅支持单=单次写入
Forward Iterator 在Input iterator基础上支持重复访问及读写
Bidirectional Iterator在Forward Iterator基础上支持自减运算符
Random-access Iterator在Bidirectional Iterator基础上已经和普通指针功能相同
### 迭代器方法
容器的begin()和end()方法可以获得首尾迭代器
```c++
for(auto it = c.begin();it!=c.end();it++)
for(auto & x : c)
```
## 排序sort
```c++
sort(begin, end, cmp(非必填))；//begin为首元素的地址，end为最后一个元素的下一个的地址，cmp为自己定义的顺序，若不填则默认升序
```

