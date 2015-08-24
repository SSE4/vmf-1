// Copyright (C) 2013, Intel Corporation, all rights reserved.

#include "test_precomp.hpp"

class TestVariant: public ::testing::Test
{
public:
    vmf::Variant v;
};

TEST_F(TestVariant, CreateUnknown)
{
    ASSERT_EQ(v.getType(), vmf::Variant::type_unknown);
}

TEST_F(TestVariant, CreateChar)
{
    vmf::Variant v((vmf::vmf_char) 'c');
    ASSERT_EQ(v.getType(), vmf::Variant::type_char);
    ASSERT_DOUBLE_EQ((vmf::vmf_char) v, 'c');
    ASSERT_DOUBLE_EQ(v.get_char(), 'c');
}

TEST_F(TestVariant, CreateInteger)
{
    vmf::Variant v((vmf::vmf_integer) 42);
    ASSERT_EQ(v.getType(), vmf::Variant::type_integer);
    ASSERT_EQ((vmf::vmf_integer) v, 42);
    ASSERT_EQ(v.get_integer(), 42);
}

TEST_F(TestVariant, CreateReal)
{
    vmf::Variant v((vmf::vmf_real) 42.42);
    ASSERT_EQ(v.getType(), vmf::Variant::type_real);
    ASSERT_DOUBLE_EQ((vmf::vmf_real) v, 42.42);
    ASSERT_DOUBLE_EQ(v.get_real(), 42.42);
}

TEST_F(TestVariant, CreateString)
{
    vmf::Variant v("string");
    ASSERT_EQ(v.getType(), vmf::Variant::type_string);
    ASSERT_EQ((vmf::vmf_string) v, "string");
    ASSERT_EQ(v.get_string(), "string");
}

TEST_F(TestVariant, CreateVec2d)
{
    vmf::vmf_vec2d vec = vmf::vmf_vec2d(42.42, 24.24);
    vmf::Variant v(vec);
    ASSERT_EQ(v.getTypeName(), "vec2d");
    bool result = v.get_vec2d() == vec;
    ASSERT_TRUE(result);
}

TEST_F(TestVariant, CreateVec3d)
{
    vmf::vmf_vec3d vec = vmf::vmf_vec3d(42.42, 24.24, 42.24);
    vmf::Variant v(vec);
    ASSERT_EQ(v.getTypeName(), "vec3d");
    bool result = v.get_vec3d() == vec;
    ASSERT_TRUE(result);
}

TEST_F(TestVariant, CreateVec4d)
{
    vmf::vmf_vec4d vec = vmf::vmf_vec4d(42.42, 24.24, 42.24, 24.42);
    vmf::Variant v(vec);
    ASSERT_EQ(v.getTypeName(), "vec4d");
    bool result = v.get_vec4d() == vec;
    ASSERT_TRUE(result);
}

TEST_F(TestVariant, CreateRawbuffer)
{
    vmf::vmf_rawbuffer rbuf("Raw <buffer \0 content>\n&", 25);
    vmf::Variant v(rbuf);
    ASSERT_EQ(v.getTypeName(), "rawbuffer");
    bool result = v.get_rawbuffer() == rbuf;
    ASSERT_TRUE(result);
}

TEST_F(TestVariant, CreateCharVector)
{
    std::vector<vmf::vmf_char> vchar;
    vchar.push_back('c');
    vchar.push_back('h');
    vmf::Variant v(vchar);
    ASSERT_EQ(v.getType(), vmf::Variant::type_char_vector);
    ASSERT_EQ(v.get_char_vector()[0], 'c');
    ASSERT_EQ(v.get_char_vector()[1], 'h');
}

TEST_F(TestVariant, CreateIntegerVector)
{
    std::vector<vmf::vmf_integer> vint;
    vint.push_back(42);
    vint.push_back(24);
    vmf::Variant v(vint);
    ASSERT_EQ(v.getType(), vmf::Variant::type_integer_vector);
    ASSERT_EQ(v.get_integer_vector()[0], 42);
    ASSERT_EQ(v.get_integer_vector()[1], 24);
}

TEST_F(TestVariant, CreateRealVector)
{
    std::vector<vmf::vmf_real> vreal;
    vreal.push_back(42.42);
    vreal.push_back(24.24);
    vmf::Variant v(vreal);
    ASSERT_EQ(v.getType(), vmf::Variant::type_real_vector);
    ASSERT_DOUBLE_EQ(v.get_real_vector()[0], 42.42);
    ASSERT_DOUBLE_EQ(v.get_real_vector()[1], 24.24);
}

TEST_F(TestVariant, CreateStringVector)
{
    std::vector<vmf::vmf_string> vstr;
    vstr.push_back("string");
    vstr.push_back("gnirts");
    vmf::Variant v(vstr);
    ASSERT_EQ(v.getType(), vmf::Variant::type_string_vector);
    ASSERT_EQ(v.get_string_vector()[0], "string");
    ASSERT_EQ(v.get_string_vector()[1], "gnirts");
}

TEST_F(TestVariant, CreateVec2dVector)
{
    vmf::vmf_vec2d vec(42.42, 24.24), vec2(24.24, 42.42);
    std::vector<vmf::vmf_vec2d> vvec;
    vvec.push_back(vec);
    vvec.push_back(vec2);
    vmf::Variant v(vvec);
    ASSERT_EQ(v.getTypeName(), "vec2d[]");
    bool result = v.get_vec2d_vector()[0] == vec;
    ASSERT_TRUE(result);
    result = v.get_vec2d_vector()[1] == vec2;
    ASSERT_TRUE(result);
}

TEST_F(TestVariant, CreateVec3dVector)
{
    vmf::vmf_vec3d vec(42.42, 24.24, 1.1), vec2(24.24, 42.42, 1.1);
    std::vector<vmf::vmf_vec3d> vvec;
    vvec.push_back(vec);
    vvec.push_back(vec2);
    vmf::Variant v(vvec);
    ASSERT_EQ(v.getTypeName(), "vec3d[]");
    bool result = v.get_vec3d_vector()[0] == vec;
    ASSERT_TRUE(result);
    result = v.get_vec3d_vector()[1] == vec2;
    ASSERT_TRUE(result);
}

TEST_F(TestVariant, CreateVec4dVector)
{
    vmf::vmf_vec4d vec(42.42, 24.24, 1.1, 128.0), vec2(24.24, 42.42, 1.1, 0.128);
    std::vector<vmf::vmf_vec4d> vvec;
    vvec.push_back(vec);
    vvec.push_back(vec2);
    vmf::Variant v(vvec);
    ASSERT_EQ(v.getTypeName(), "vec4d[]");
    bool result = v.get_vec4d_vector()[0] == vec;
    ASSERT_TRUE(result);
    result = v.get_vec4d_vector()[1] == vec2;
    ASSERT_TRUE(result);
}

TEST_F(TestVariant, GetTypeNameUnknown)
{
    ASSERT_EQ(v.getTypeName(), "unknown");
}

TEST_F(TestVariant, GetTypeNameChar)
{
    vmf::Variant v((vmf::vmf_char) 'c');
    ASSERT_EQ(v.getTypeName(), "char");
}

TEST_F(TestVariant, GetTypeNameInteger)
{
    vmf::Variant v((vmf::vmf_integer) 42);
    ASSERT_EQ(v.getTypeName(), "integer");
}

TEST_F(TestVariant, GetTypeNameReal)
{
    vmf::Variant v((vmf::vmf_real) 42.42);
    ASSERT_EQ(v.getTypeName(), "real");
}

TEST_F(TestVariant, GetTypeNameString)
{
    vmf::Variant v("string");
    ASSERT_EQ(v.getTypeName(), "string");
}

TEST_F(TestVariant, GetTypeNameVec2d)
{
    vmf::vmf_vec2d vec = vmf::vmf_vec2d(42.42, 24.24);
    vmf::Variant v(vec);
    ASSERT_EQ(v.getTypeName(), "vec2d");
}

TEST_F(TestVariant, GetTypeNameVec3d)
{
    vmf::vmf_vec3d vec = vmf::vmf_vec3d(42.42, 24.24, 42.24);
    vmf::Variant v(vec);
    ASSERT_EQ(v.getTypeName(), "vec3d");
}

TEST_F(TestVariant, GetTypeNameVec4d)
{
    vmf::vmf_vec4d vec = vmf::vmf_vec4d(42.42, 24.24, 42.24, 24.42);
    vmf::Variant v(vec);
    ASSERT_EQ(v.getTypeName(), "vec4d");
}

TEST_F(TestVariant, GetTypeNameRawbuffer)
{
    vmf::vmf_rawbuffer rbuf("Raw <buffer \0 content>\n&", 25);
    vmf::Variant v(rbuf);
    ASSERT_EQ(v.getTypeName(), "rawbuffer");
}

TEST_F(TestVariant, GetTypeNameCharVector)
{
    std::vector<vmf::vmf_char> vchar;
    vchar.push_back('c');
    vchar.push_back('h');
    vmf::Variant v(vchar);
    ASSERT_EQ(v.getTypeName(), "char[]");
}

TEST_F(TestVariant, GetTypeNameIntegerVector)
{
    std::vector<vmf::vmf_integer> vint;
    vint.push_back(42);
    vint.push_back(24);
    vmf::Variant v(vint);
    ASSERT_EQ(v.getTypeName(), "integer[]");
}

TEST_F(TestVariant, GetTypeNameRealVector)
{
    std::vector<vmf::vmf_real> vreal;
    vreal.push_back(42.42);
    vreal.push_back(24.24);
    vmf::Variant v(vreal);
    ASSERT_EQ(v.getTypeName(), "real[]");
}

TEST_F(TestVariant, GetTypeNameStringVector)
{
    std::vector<vmf::vmf_string> vstr;
    vstr.push_back("string");
    vstr.push_back("gnirts");
    vmf::Variant v(vstr);
    ASSERT_EQ(v.getTypeName(), "string[]");
}

TEST_F(TestVariant, GetTypeNameVec2dVector)
{
    vmf::vmf_vec2d vec(42.42, 24.24), vec2(24.24, 42.42);
    std::vector<vmf::vmf_vec2d> vvec;
    vvec.push_back(vec);
    vvec.push_back(vec2);
    vmf::Variant v(vvec);
    ASSERT_EQ(v.getTypeName(), "vec2d[]");
}

TEST_F(TestVariant, GetTypeNameVec3dVector)
{
    vmf::vmf_vec3d vec(42.42, 24.24, 1.1), vec2(24.24, 42.42, 1.1);
    std::vector<vmf::vmf_vec3d> vvec;
    vvec.push_back(vec);
    vvec.push_back(vec2);
    vmf::Variant v(vvec);
    ASSERT_EQ(v.getTypeName(), "vec3d[]");
    bool result = v.get_vec3d_vector()[0] == vec;
    ASSERT_TRUE(result);
}

TEST_F(TestVariant, GetTypeNameVec4dVector)
{
    vmf::vmf_vec4d vec(42.42, 24.24, 1.1, 128.0), vec2(24.24, 42.42, 1.1, 0.128);
    std::vector<vmf::vmf_vec4d> vvec;
    vvec.push_back(vec);
    vvec.push_back(vec2);
    vmf::Variant v(vvec);
    ASSERT_EQ(v.getTypeName(), "vec4d[]");
}

TEST_F(TestVariant, MaxLimitUnknown)
{
    EXPECT_THROW(vmf::Variant::maxLimit<vmf::vmf_integer>(vmf::Variant::type_unknown), vmf::IncorrectParamException);
}

TEST_F(TestVariant, MaxLimitChar)
{
    vmf::vmf_char limitChar = vmf::Variant::maxLimit<vmf::vmf_char>(vmf::Variant::type_char);
    ASSERT_EQ(limitChar, std::numeric_limits<vmf::vmf_char>::max());
}

TEST_F(TestVariant, MaxLimitInteger)
{
    vmf::vmf_integer limitValue = vmf::Variant::maxLimit<vmf::vmf_integer>(vmf::Variant::type_integer);
    ASSERT_EQ(limitValue, std::numeric_limits<vmf::vmf_integer>::max());
}

TEST_F(TestVariant, MaxLimitReal)
{
    vmf::vmf_real limitReal = vmf::Variant::maxLimit<vmf::vmf_real>(vmf::Variant::type_real);
    ASSERT_DOUBLE_EQ(limitReal, std::numeric_limits<vmf::vmf_real>::max());
}

TEST_F(TestVariant, MinLimitUnknown)
{
    EXPECT_THROW(vmf::Variant::minLimit<vmf::vmf_integer>(vmf::Variant::type_unknown), vmf::IncorrectParamException);
}

TEST_F(TestVariant, MinLimitChar)
{
    vmf::vmf_char limitChar = vmf::Variant::minLimit<vmf::vmf_char>(vmf::Variant::type_char);
    ASSERT_EQ(limitChar, std::numeric_limits<vmf::vmf_char>::lowest());
}

TEST_F(TestVariant, MinLimitInteger)
{
    vmf::vmf_integer limitValue = vmf::Variant::minLimit<vmf::vmf_integer>(vmf::Variant::type_integer);
    ASSERT_EQ(limitValue, std::numeric_limits<vmf::vmf_integer>::lowest());
}

TEST_F(TestVariant, MinLimitReal)
{
    vmf::vmf_real limitReal = vmf::Variant::minLimit<vmf::vmf_real>(vmf::Variant::type_real);
    ASSERT_DOUBLE_EQ(limitReal, std::numeric_limits<vmf::vmf_real>::lowest());
}

TEST_F(TestVariant, FromStringUnknown)
{
    v.fromString(vmf::Variant::type_unknown, "noType");
}

TEST_F(TestVariant, FromStringChar)
{
    v.fromString(vmf::Variant::type_char, "c");
    ASSERT_EQ(v.getType(), vmf::Variant::type_char);
    ASSERT_EQ((vmf::vmf_char) v, 'c');
}

TEST_F(TestVariant, FromStringInteger)
{
    v.fromString(vmf::Variant::type_integer, "42");
    ASSERT_EQ(v.getType(), vmf::Variant::type_integer);
    ASSERT_EQ((vmf::vmf_integer) v, 42);
}

TEST_F(TestVariant, FromStringReal)
{
    v.fromString(vmf::Variant::type_real, "42.42");
    ASSERT_EQ(v.getType(), vmf::Variant::type_real);
    ASSERT_EQ((vmf::vmf_real) v, 42.42);
}

TEST_F(TestVariant, FromStringString)
{
    v.fromString(vmf::Variant::type_string, "string");
    ASSERT_EQ(v.getType(), vmf::Variant::type_string);
    ASSERT_EQ((vmf::vmf_string) v, "string");
}

TEST_F(TestVariant, ToStringFromStringVectorChar)
{
    std::vector<vmf::vmf_char> vchar;
    vchar.push_back('c');
    vchar.push_back('h');
    vchar.push_back('a');
    vchar.push_back('r');
    v = vmf::Variant(vchar);
    vmf::Variant v2;
    v2.fromString(vmf::Variant::type_char_vector, v.toString());
    ASSERT_TRUE(v == v2);
}

TEST_F(TestVariant, ToStringFromStringVectorInteger)
{
    std::vector<vmf::vmf_integer> vint;
    vint.push_back(42);
    vint.push_back(24);
    vint.push_back(0);
    vint.push_back(1);
    v = vmf::Variant(vint);
    vmf::Variant v2;
    v2.fromString(vmf::Variant::type_integer_vector, v.toString());
    ASSERT_TRUE(v == v2);
}

TEST_F(TestVariant, ToStringFromStringVectorReal)
{
    std::vector<vmf::vmf_real> vreal;
    vreal.push_back(0.0);
    vreal.push_back(1.1);
    vreal.push_back(2.2);
    vreal.push_back(3.3);
    v = vmf::Variant(vreal);
    vmf::Variant v2;
    v2.fromString(vmf::Variant::type_real_vector, v.toString());
    ASSERT_TRUE(v == v2);
}

TEST_F(TestVariant, ToStringFromStringVectorString)
{
    std::vector<vmf::vmf_string> vstring;
    vstring.push_back("s 0");
    vstring.push_back("s 1");
    vstring.push_back("s 2");
    vstring.push_back("s 3 test");
    v = vmf::Variant(vstring);
    vmf::Variant v2;
    v2.fromString(vmf::Variant::type_string_vector, v.toString());
    ASSERT_TRUE(v == v2);
}

TEST_F(TestVariant, ToStringFromStringVectorVec2d)
{
    std::vector<vmf::vmf_vec2d> vvec2d;
    vvec2d.push_back(vmf::vmf_vec2d(0,0));
    vvec2d.push_back(vmf::vmf_vec2d(1,1));
    vvec2d.push_back(vmf::vmf_vec2d(2,2));
    vvec2d.push_back(vmf::vmf_vec2d(3,3));
    v = vmf::Variant(vvec2d);
    vmf::Variant v2;
    v2.fromString(vmf::Variant::type_vec2d_vector, v.toString());
    ASSERT_TRUE(v == v2);
}

TEST_F(TestVariant, ToStringFromStringVectorVec3d)
{
    std::vector<vmf::vmf_vec3d> vvec3d;
    vvec3d.push_back(vmf::vmf_vec3d(0,0,0));
    vvec3d.push_back(vmf::vmf_vec3d(1,1,1));
    vvec3d.push_back(vmf::vmf_vec3d(2,2,2));
    vvec3d.push_back(vmf::vmf_vec3d(3,3,3));
    v = vmf::Variant(vvec3d);
    vmf::Variant v2;
    v2.fromString(vmf::Variant::type_vec3d_vector, v.toString());
    ASSERT_TRUE(v == v2);
}

TEST_F(TestVariant, ToStringFromStringVectorVec4d)
{
    std::vector<vmf::vmf_vec4d> vvec4d;
    vvec4d.push_back(vmf::vmf_vec4d(0,0,0,0));
    vvec4d.push_back(vmf::vmf_vec4d(1,1,1,1));
    vvec4d.push_back(vmf::vmf_vec4d(2,2,2,2));
    vvec4d.push_back(vmf::vmf_vec4d(3,3,3,3));
    v = vmf::Variant(vvec4d);
    vmf::Variant v2;
    v2.fromString(vmf::Variant::type_vec4d_vector, v.toString());
    ASSERT_TRUE(v == v2);
}

TEST_F(TestVariant, ConvertInc)
{
    v = vmf::Variant((vmf::vmf_real) 42.42);
    EXPECT_THROW(v.convertTo(vmf::Variant::type_string), vmf::TypeCastException);
}

TEST_F(TestVariant, IntConstructor)
{
    int value = 42;
    v = vmf::Variant(value);
    ASSERT_EQ(value, (vmf::vmf_integer) v);
}

TEST_F(TestVariant, FloatConstructor)
{
    float value = 42.0f;
    v = vmf::Variant(value);
    ASSERT_DOUBLE_EQ(value, (vmf::vmf_real) v);
}

TEST_F(TestVariant, VectorIntConstructor)
{
    std::vector<int> value;
    value.push_back(42);
    value.push_back(24);
    v = vmf::Variant(value);
    ASSERT_EQ(value[0], v.get_integer_vector()[0]);
    ASSERT_EQ(value[1], v.get_integer_vector()[1]);
}

TEST_F(TestVariant, VectorFloatConstructor)
{
    std::vector<float> value;
    value.push_back(42.42f);
    value.push_back(24.24f);
    v = vmf::Variant(value);
    ASSERT_DOUBLE_EQ(value[0], v.get_real_vector()[0]);
    ASSERT_DOUBLE_EQ(value[1], v.get_real_vector()[1]);
}

TEST_F(TestVariant, typeFromString)
{
    ASSERT_EQ(v.typeFromString(""), vmf::Variant::type_unknown);
    ASSERT_EQ(v.typeFromString("invalid type"), vmf::Variant::type_unknown);

    ASSERT_EQ(v.typeFromString("unknown"), vmf::Variant::type_unknown);
    ASSERT_EQ(v.typeFromString("char"), vmf::Variant::type_char);
    ASSERT_EQ(v.typeFromString("integer"), vmf::Variant::type_integer);
    ASSERT_EQ(v.typeFromString("real"), vmf::Variant::type_real);
    ASSERT_EQ(v.typeFromString("string"), vmf::Variant::type_string);
    ASSERT_EQ(v.typeFromString("vec2d"), vmf::Variant::type_vec2d);
    ASSERT_EQ(v.typeFromString("vec3d"), vmf::Variant::type_vec3d);
    ASSERT_EQ(v.typeFromString("vec4d"), vmf::Variant::type_vec4d);
    ASSERT_EQ(v.typeFromString("rawbuffer"), vmf::Variant::type_rawbuffer);

    ASSERT_EQ(v.typeFromString("char[]"), vmf::Variant::type_char_vector);
    ASSERT_EQ(v.typeFromString("integer[]"), vmf::Variant::type_integer_vector);
    ASSERT_EQ(v.typeFromString("real[]"), vmf::Variant::type_real_vector);
    ASSERT_EQ(v.typeFromString("string[]"), vmf::Variant::type_string_vector);
    ASSERT_EQ(v.typeFromString("vec2d[]"), vmf::Variant::type_vec2d_vector);
    ASSERT_EQ(v.typeFromString("vec3d[]"), vmf::Variant::type_vec3d_vector);
    ASSERT_EQ(v.typeFromString("vec4d[]"), vmf::Variant::type_vec4d_vector);
}

class TestVariantVectorTypes : public ::testing::Test
{
protected:
    void SetUp()
    {
        x = 42.42;
        y = 24.24;
        z = 42.24;
        w = 24.42;
    }
    vmf::vmf_real x, y, z, w;
    vmf::Variant v1, v2;
};

TEST_F(TestVariantVectorTypes, ToStringFromStringvec2d)
{
    vmf::vmf_vec2d vec(x, y);
    v1 = vmf::Variant(vec);
    v2.fromString(vmf::Variant::type_vec2d, v1.toString());
    bool result = v1 == v2;
    ASSERT_TRUE(result);
    ASSERT_FALSE(vec == vmf::vmf_vec2d());
}

TEST_F(TestVariantVectorTypes, ToStringFromStringvec3d)
{
    vmf::vmf_vec3d vec(x, y, z);
    v1 = vmf::Variant(vec);
    v2.fromString(vmf::Variant::type_vec3d, v1.toString());
    bool result = v1 == v2;
    ASSERT_TRUE(result);
    ASSERT_FALSE(vec == vmf::vmf_vec3d());
}

TEST_F(TestVariantVectorTypes, ToStringFromStringvec4d)
{
    vmf::vmf_vec4d vec(x, y, z, w);
    v1 = vmf::Variant(vec);
    v2.fromString(vmf::Variant::type_vec4d, v1.toString());
    bool result = v1 == v2;
    ASSERT_TRUE(result);
    ASSERT_FALSE(vec == vmf::vmf_vec4d());
}

class TestVariantRawByfferType : public ::testing::TestWithParam<size_t>
{
protected:
    std::unique_ptr<char[]> data;
    vmf::Variant v1, v2;
};

TEST_P(TestVariantRawByfferType, ToStringFromString)
{
    size_t size = GetParam();
    switch(size)
    {
    case 0:
        ASSERT_THROW(vmf::vmf_rawbuffer("", 0), vmf::IncorrectParamException);
        ASSERT_THROW(vmf::vmf_rawbuffer(0, 10), vmf::IncorrectParamException);
        ASSERT_NO_THROW(vmf::vmf_rawbuffer(0, 0));
        return;
    default:
        data = std::unique_ptr<char[]>(new char[size]);
        for(unsigned int i = 0; i < size; i++)
            data[i] = (unsigned char)i;
        break;
    }
    vmf::vmf_rawbuffer rbuf(data.get(), size);
    v1 = vmf::Variant(rbuf);
    v2.fromString(vmf::Variant::type_rawbuffer, v1.toString());
    bool result = v1 == v2;
    ASSERT_TRUE(result);
}

INSTANTIATE_TEST_CASE_P(UnitTest, TestVariantRawByfferType, ::testing::Values(0, 1, 2, 3, 4, 5, 512) );

class TestVariantRawBuffer_Base64Encoding : public ::testing::TestWithParam<std::tuple<const char*, size_t>>
{
protected:
    const char* data;
    vmf::Variant v1, v2;
};

TEST_P(TestVariantRawBuffer_Base64Encoding, TestEncode)
{
    data = std::get<0>(GetParam());
    size_t size = std::get<1>(GetParam());

    vmf::vmf_rawbuffer rbuf(data, size);
    v1 = vmf::Variant(rbuf);
    std::string result = v1.toString();
    if(rbuf == vmf::vmf_rawbuffer(0,0))
        ASSERT_EQ(result, "");
    else if( rbuf == vmf::vmf_rawbuffer("\0", 1) )
        ASSERT_EQ(result, "AA==");
    else if( rbuf == vmf::vmf_rawbuffer("foob", 4) )
        ASSERT_EQ(result, "Zm9vYg==");
    else if( rbuf == vmf::vmf_rawbuffer("foobar", 6) )
        ASSERT_EQ(result, "Zm9vYmFy");
}

INSTANTIATE_TEST_CASE_P(UnitTest, TestVariantRawBuffer_Base64Encoding, ::testing::Values( std::make_tuple((char*)0, 0), std::make_tuple("\0", 1),
    std::make_tuple("foob", 4), std::make_tuple("foobar", 6) ) );

class TestVariantRawBuffer_Base64Decoding : public ::testing::TestWithParam<std::tuple<const char*, unsigned int>>
{
protected:
    const char* data;
    vmf::Variant v1, v2;
};

TEST_P(TestVariantRawBuffer_Base64Decoding, TestDecode)
{
    data = std::get<0>(GetParam());
    unsigned int idx = std::get<1>(GetParam());
    switch(idx)
    {
    case 0:
        ASSERT_THROW(v1.fromString(vmf::Variant::type_rawbuffer, data), vmf::IncorrectParamException);
        break;
    case 1:
        ASSERT_THROW(v1.fromString(vmf::Variant::type_rawbuffer, data), vmf::IncorrectParamException);
        break;
    case 2:
        ASSERT_THROW(v1.fromString(vmf::Variant::type_rawbuffer, data), vmf::IncorrectParamException);
        break;
    case 3:
        {
            v1.fromString(vmf::Variant::type_rawbuffer, data);
            vmf::vmf_rawbuffer rbuf("foob\0\0", 6);
            v2 = vmf::Variant(rbuf);
            bool result = v1 == v2;
            ASSERT_TRUE(result);
            break;
        }
    case 4:
        {
            v1.fromString(vmf::Variant::type_rawbuffer, data);
            v2 = vmf::Variant(vmf::vmf_rawbuffer());
            bool result = v1 == v2;
            ASSERT_TRUE(result);
            break;
        }
    }
}

INSTANTIATE_TEST_CASE_P(UnitTest, TestVariantRawBuffer_Base64Decoding, ::testing::Values( std::make_tuple("Zm9==vYgAA", 0), std::make_tuple("AA===", 1),
    std::make_tuple("Zm9vY-gA", 2), std::make_tuple("Zm9vYgAA", 3), std::make_tuple("", 4) ) );