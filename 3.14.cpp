#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
class Contact{
protected:
    string name,number;
public:
    friend istream& operator>>(istream& in,Contact& c);
    friend ostream& operator<<(ostream& out,Contact& c);
    friend void ArrayInPhone();
    static bool CheckA(string number);
    string get_number(){
        return number;
    }
    friend void Add_Phone();
    static void Delete(string c_number);
    static void Modify(string c_number);
    static void PhoneInArray();
    static void Check(string c_name);
    static void Reflect();
    friend void ContacterPhoneCopySIM();
    friend void ContacterSIMCopyPhone();
};
class IdContact:public Contact{
    string home,qq_n;
public:
    friend istream& operator>>(istream& in,IdContact& c);
    friend ostream& operator<<(ostream& out,IdContact& c);
    friend void ArrayInSim();
    static bool CheckI(string number);
    friend  void Add_IdC();
    static void Delete(string c_number);
    static void Modify(string c_number);
    static void SIMInArray();
    static void Check(string c_name);
    static void Reflect();
    friend void ContacterPhoneCopySIM();
    friend void ContacterSIMCopyPhone();
};
int cntP=0;
int cntS=0;
Contact phone[1005];
IdContact SIM[1005];
void ArrayInSim(){
    ofstream ofs;
    ofs.open("E:\\homework\\idcard.txt",ios::out);
    if( !ofs.is_open() ){
        cout<<"文件打开失败"<<endl;
        return;
    }
    for(int i=1;i<=cntS;i++){
        ofs<<SIM[i].name<<" "<<SIM[i].number<<" "<<SIM[i].home<<" "<<SIM[i].qq_n<<endl;
    }
    ofs.close();
}
void ArrayInPhone(){
    ofstream ofs;
    ofs.open("E:\\homework\\phone.txt",ios::out);
    if( !ofs.is_open() ){
        cout<<"文件打开失败"<<endl;
        return;
    }
    for(int i=1;i<=cntP;i++){
        ofs<<phone[i].name<<" "<<phone[i].number<<'\n';
    }
    ofs.close();

}
void Contact::PhoneInArray(){
    ifstream ifs;
    ifs.open("E:\\homework\\phone.txt",ios::in);
    if( !ifs.is_open() ){
        cout<<"文件打开失败"<<endl;
        return;
    }
    string name,number;
    while(ifs>>name>>number){
        cntP++;
        phone[cntP].name=name;
        phone[cntP].number=number;
        if(cntP>1000){
            cout<<"手机联系人数量超出1000上限"<<endl;
        }
    }
    ifs.close();
}
void IdContact::SIMInArray(){
    ifstream ifs;
    ifs.open("E:\\homework\\idcard.txt",ios::in);
    if( !ifs.is_open() ){
        cout<<"文件打开失败"<<endl;
        return;
    }
    string name, number,home,qq_n;
    while(ifs >> name >> number>>home>>qq_n){
       cntS++;
       SIM[cntS].name=name;
       SIM[cntS].number=number;
       SIM[cntS].home=home;
       SIM[cntS].qq_n=qq_n;
        if(cntS>1000){
            cout<<"手机卡联系人数量超出1000上限"<<endl;
        }
    }
    ifs.close();
}
istream& operator>>(istream& in,Contact& c){
    in>>c.name>>c.number;
    return in;
}
ostream& operator<<(ostream& out,Contact& c){
    out<<c.name<<' '<<c.number;
    return out;
}
istream& operator>>(istream& in,IdContact& c){
    in>>c.name>>c.number>>c.home>>c.qq_n;
    return in;
}
ostream& operator<<(ostream& out,IdContact& c){
    out<<c.name<<" "<<c.number<<" "<<c.home<<" "<<c.qq_n<<" ";
    return out;
}
bool Contact::CheckA(string number){
    ifstream ifs;
    ifs.open("E:\\homework\\phone.txt",ios::in);
    if( !ifs.is_open() ){
        return true;
    }
    string name, phone;
    while(ifs >> name >> phone){
        if(phone == number){
            return false;
        }
    }
    ifs.close();
    return true;
}
bool IdContact::CheckI(string number){
    ifstream ifs;
    ifs.open("E:\\homework\\idcard.txt",ios::in);
    if( !ifs.is_open() ){
        return true;
    }
    string name, phone,home,qq_n;
    while(ifs >> name >> phone>>home>>qq_n){
        if(phone == number){
            return false;
        }
    }
    ifs.close();
    return true;
}
void Add_Phone(){
    cout<<"请输入存储在手机中的联系人的姓名和电话号码: "<<endl;
    Contact c;
    cin>>c;
    if(!Contact::CheckA(c.get_number())){
        cout<<"该电话号码已经存在，请重新输入"<<endl;
        return;
    }
    if(cntP >= 1000) { 
        cout << "通讯录已满！" << endl;
        return;
    }
    cntP++;
    phone[cntP]=c;
    ArrayInPhone();
}
void Add_IdC(){
    IdContact c;
    cout<<"请输入输入存储在电话卡中的联系人的姓名,电话号码,籍贯和QQ号码,用空格分隔"<<endl;
    cin>>c;
    if(!IdContact::CheckI(c.get_number())){
        cout<<"该电话号码已经存在，请重新输入";
        return;
    }
    if(cntS >= 1000) { 
        cout << "通讯录已满！" << endl;
        return;
    }
    cntS++;
    SIM[cntS]=c;
    ArrayInSim();
}
void Contact::Delete(string c_number){
        int i;
        bool ans=false;
        for(i=1;i<=cntP;i++){
            if(phone[i].number==c_number){      
                ans=true;
                break;
            }
        }
        if(ans){
            if(i<cntP){
                for(int j=i;j<cntP;j++)
                    swap(phone[j],phone[j+1]);        
            }
            cntP--;
            cout<<"成功找到了这个联系人并在手机中进行了删除"<<endl;
        }
        else cout<<"没有在手机中找到你提供的联系人"<<endl;
}
void IdContact::Delete(string c_number){
        int i;
        bool ans=false;
        for(i=1;i<=cntS;i++){
            if(SIM[i].number==c_number){      
                ans=true;
                break;
            }
        }
        if(ans){
            if(i<cntS){
                for(int j=i;j<cntS;j++)
                    swap(SIM[j],SIM[j+1]);       
            }
            cntS--; 
            cout<<"成功找到了这个联系人并在手机卡中进行了删除"<<endl;
        } else  cout<<"没有在手机卡中找到你提供的联系人"<<endl;
    }
void DeleteContacter(){
    string c_number;
    cout<<"请输入你想要删除的联系人的手机号码："<<endl;
    cin>>c_number;
    Contact::Delete(c_number);
    IdContact::Delete(c_number);
    ArrayInPhone();
    ArrayInSim();
}
void Contact::Modify(string c_number){
        int i;
        bool ans=false;
        for(i=1;i<=cntP;i++){
            if(phone[i].number==c_number){      
                ans=true;
                break;
            }
        }
        if(ans){
            cout<<"在手机中成功找到了这个联系人，请输入需改后的信息。姓名： 电话号码："<<endl;
            Contact c;
            cin>>c;
            phone[i]=c;
        }
        else cout<<"没有在手机中找到你提供的联系人"<<endl;
}
void IdContact::Modify(string c_number){
        int i;
        bool ans=false;
        for(i=1;i<=cntP;i++){
            if(SIM[i].number==c_number){      
                ans=true;
                break;
            }
        }
        if(ans){
            cout<<"在手机卡中成功找到了这个联系人，请输入需改后的信息。姓名： 电话号码： 籍贯： QQ号："<<endl;
            IdContact c;
            cin>>c;
            SIM[i]=c;
        }
        else cout<<"没有在手机卡中找到你提供的联系人"<<endl;
}
void ModifyContacter(){
    string c_number;
    cout<<"请输入你想要修改的联系人的手机号码："<<endl;
    cin>>c_number;
    Contact::Modify(c_number);
    IdContact::Modify(c_number);
    ArrayInPhone();
    ArrayInSim();
}
void Contact::Check(string c_name){
    int i=1;
    bool ans=false;
    for(i;i<=cntP;i++){
        if( phone[i].name==c_name ){
            ans=true;
            cout<<"在手机中成功查到了这个联系人的信息，这个联系人的姓名和电话号码分别为："<<endl;
            cout<<phone[i]<<endl;
        }
    }
    if(!ans) cout<<"没能在在手机中查到了这个联系人的信息"<<endl;
}
void IdContact::Check(string c_name){
     int i=1;
    bool ans=false;
    for(i;i<=cntS;i++){
        if( SIM[i].name==c_name ){
            ans=true;
            cout<<"在手机卡中成功查到了这个联系人的信息，这个联系人的姓名，电话号码，籍贯，QQ号分别为："<<endl;
            cout<<SIM[i]<<endl;
        }
    }
    if(!ans) cout<<"没能在在手机卡中查到了这个联系人的信息"<<endl;
}
void CheckContacter(){
    cout<<"请输入你要查询的联系人的姓名："<<endl;
    string c_name;
    cin>>c_name;
    Contact::Check(c_name);
    IdContact::Check(c_name);
}
void Contact::Reflect(){
    for(int i=1;i<=cntP;i++){
        cout<<phone[i]<<endl;
    }
}
void IdContact::Reflect(){
    for(int i=1;i<=cntS;i++){
        cout<<SIM[i]<<endl;
    }
}
void ReflectAllContacter(){
    cout<<"1：显示手机中所有联系人的信息："<<endl;
    Contact::Reflect();
    cout<<"2：显示手机卡中所有联系人的信息："<<endl;
    IdContact::Reflect();
}
void ContacterPhoneCopySIM(){//将联系人的信息从手机转存到手机卡上
    if(cntP+cntS>1000){
        cout<<"无法进行操作，因为转存后会使手机卡上的联系人总数大于1000"<<endl;
        return;
    }
    int piovt=cntS;
    for(int i=1;i<=cntP;i++){
        bool ans=false;
        for(int j=1;j<=piovt;j++){
            if(phone[i].name==SIM[j].name&&phone[i].number==SIM[j].number){
                ans=true;
                break;
            }
        }
        if(!ans){
            SIM[++cntS].name=phone[i].name;
            SIM[cntS].number=phone[i].number;
        }    
    }
    ArrayInSim();
    cout<<"操作成功，已经将手机上的联系人转存到手机卡上"<<endl;
}
void ContacterSIMCopyPhone(){
    if(cntP+cntS>1000){
        cout<<"无法进行操作，因为转存后会使手机上的联系人总数大于1000"<<endl;
        return;
    }
    int piovt=cntP;
    for(int i=1;i<=cntS;i++){
        bool ans=false;
        for(int j=1;j<=piovt;j++){
            if(phone[j].name==SIM[i].name&&phone[j].number==SIM[i].number){
                ans=true;
                break;
            }
        }
        if(!ans){
            phone[++cntP].name=SIM[i].name;
            phone[cntP].number=SIM[i].number;
        }    
    }
    ArrayInPhone();
    cout<<"操作成功，已经将手机卡上的联系人转存到手机上"<<endl;
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    Contact::PhoneInArray();
    IdContact::SIMInArray();
    int choice;
    while (true) {
        cout << "\n========== 通讯录管理系统 ==========" << endl;
        cout << "1. 录入联系人信息在手机上" << endl;
        cout << "2. 录入联系人信息在电话卡上" << endl;
        cout << "3. 删除一个联系人的信息" << endl;
        cout << "4. 修改一个联系人的信息" << endl;
        cout << "5. 根据名字查询联系人信息" << endl;
        cout << "6. 显示所有联系人的信息"<<endl;
        cout << "7. 将联系人的信息从手机转存到手机卡上"<<endl;
        cout << "8. 将联系人的信息从手机卡上转存到手机上"<<endl;
        cout << "0. 退出系统" << endl;
        cout << "请输入操作编号: ";
        cin>>choice;
    switch (choice) {
            case 1: Add_Phone(); continue;
            case 2: Add_IdC(); continue;
            case 3: DeleteContacter();continue;
            case 4: ModifyContacter();continue;
            case 5: CheckContacter();continue;
            case 6: ReflectAllContacter();continue;
            case 7: ContacterPhoneCopySIM();continue;
            case 8: ContacterSIMCopyPhone();continue;
            case 0: cout << "退出系统，再见！" << endl; 
            return 0;}
    }
}
