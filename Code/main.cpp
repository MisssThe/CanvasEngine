#include <iostream>
#include <fstream>
#include "Include/Framework/Assets/AssetManager.h"

class A:public CustomAsset{
public:
    std::string Type() override {
        return "A";
    }
    int e;
protected:
    void SerializeInInternal(cereal::BinaryInputArchive &archive) override {
        archive(e);
    }

    void SerializeOutInternal(cereal::BinaryOutputArchive &archive) override {
        archive(e);
    }
};

class B : public CustomAsset {
public:
    std::string Type() override {
        return "B";
    }
    int a,b,c;
    var<A> d;
protected:
    void SerializeInInternal(cereal::BinaryInputArchive &archive) override {
        archive(a,b,c,d);
    }

    void SerializeOutInternal(cereal::BinaryOutputArchive &archive) override {
        archive(a,b,c,d);
    }
};
struct MyRecord
{
    uint8_t x, y;
    float z;

    template <class Archive>
    void serialize( Archive & ar )
    {
        ar( x, y, z );
    }
};

struct SomeData
{
    int32_t id;
    std::shared_ptr< MyRecord> data;

    template <class Archive>
    void save( Archive & ar ) const
    {
        ar( data );
    }

    template <class Archive>
    void load( Archive & ar )
    {
        static int32_t idGen = 0;
        id = idGen++;
        ar( data );
    }
};


REFLECT_REGISTER(B);
int main() {
//    var b = new_ptr<B>();
//    b->a = 11;
//    b->b = 22;
//    b->c = 33;
//    var a = new_ptr<A>();
//    a->e = 44;b->d = a;
//    AssetManager::Create("hhh.asset", b);
////    var<B> f = safe_cast<B> (AssetManager::Instance("hhh.asset"));



    std::ofstream os("out.cereal", std::ios::binary);
    cereal::BinaryOutputArchive archive( os );

    SomeData myData;
    archive( myData );

    return 0;
    return 0;
}
