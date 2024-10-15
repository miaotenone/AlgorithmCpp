//
// Created by 14771 on 2024/9/2.
//
#include "iostream"
#include "memory"
//using namespace std::string_literals;
class Entity{
private:
    int m_age;
    std::string m_name;
public:
    Entity():m_age(-1), m_name("name"){std::cout<<"created"<<std::endl;}
    Entity(const std::string& name)
    :m_age(-1), m_name(name){}
    Entity(int age)
    :m_age(age),m_name("unknown"){}
    ~Entity(){std::cout<<"destroyed"<<std::endl;}
    std::string get_name() const{return m_name;}
};

class cl1{
public:
    Entity* e;
    cl1(Entity* entity):e(entity){}
    ~cl1(){delete e;}
};

void PrintEntity(const Entity& e){
    std::cout<<e.get_name()<<std::endl;
}

struct Vector2 {
    double a,b;
    Vector2(double a1,double b1)
    :a(a1),b(b1){}
    Vector2 add(const Vector2& other)const
    {
        return Vector2(a+other.a,b+other.b);
    }
    Vector2 operator+(const Vector2& other)const
    {
        return this->add(other);
    }
    Vector2 multipy(const Vector2& other)const
    {
        return *this*other;
    }
    Vector2 operator*(const Vector2& other) const
    {
        return Vector2(other.a*a,other.b*b);
    }
    bool operator==(const Vector2& other) const
    {
        return a==other.a&&b==other.b;
    }
    bool operator!=(const Vector2& other) const
    {
        return !(*this==other);
    }
};
std::ostream& operator<<(std::ostream& ostream,Vector2 other){
    ostream<<other.a<<','<<other.b;
}

int main(){
    union{
        float a;
        int b ;
    };
    a=2.0f;
std::cout<<a<<std::endl;
std::cout<<b<<std::endl;
//    {
//        cl1 cl(new Entity());
//    }
    { std::shared_ptr<Entity> e11 ;
        {
//        std::unique_ptr<Entity> up = std::make_unique<Entity>();
            std::shared_ptr<Entity> sharedPtr = std::make_shared<Entity>();
            e11 = sharedPtr;
//        std::weak_ptr<Entity> wp = sharedPtr;
        }
    }


//    Vector2 vec1(1,4);
//    Vector2 vec2(2,3);
//    Vector2 vecm(1.1,1.1);
//    Vector2 re = vec1.add(vec2);
//    Vector2 res = vec1+vec2;
//    Vector2 m_res1 = vec1*vecm;
//    Vector2 m_res2 = vec1.multipy(vecm);
//    std::cout<<re<<std::endl;
//    std::cout<<res<<std::endl;
//    std::cout<<m_res1<<std::endl;
//    std::cout<<m_res2<<std::endl;
//    std::cout<<(vec1==vec2)<<std::endl;
//    std::cout<<(vec1!=vec2)<<std::endl;


    //implicit conversion
//    Entity e = 22;
//    Entity e1 = (std::string)"xxxxxx";
//    PrintEntity(22);
//    PrintEntity((std::string)"sdfe");//only once conversion
//    std::cin.get();
//    const char* name = u8"xiaoming";
//    const wchar_t* name2 = L"xx";
//    const char16_t* name3 = u"oooo";
//    const char32_t* name4 = U"dgfj";
//
//    std::string name0 = "ddff"s + "dgfg";
//    std::wstring name01 = L"ddff"s + L"dgfg";
//    std::u32string name02 = U"ddff"s + U"dgfg";
//
//    const char* example = "line1\n"
//                          "line2\n"
//                          "line3\n";
//    const char* ex = R"(line
//line2
//line3)";


}