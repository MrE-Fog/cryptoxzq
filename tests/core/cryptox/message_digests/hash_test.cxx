// [===========================================================================]
// [                               C r y p t o x                               ]
// [---------------------------------------------------------------------------]
// [                                                                           ]
// [                          Copyright (C) 2016-2017                          ]
// [                      Rodrigo Madera <madera@acm.org>                      ]
// [                                                                           ]
// [---------------------------------------------------------------------------]
// [                            All Rights Reserved                            ]
// [===========================================================================]

#include "pch.hxx"
#include <cryptox/message_digests/hash.hxx>
#include <vector>
#include <string>
using namespace cryptox;

static const std::string empty_string;
static const std::string lazy_dog = "The quick brown fox jumps over the lazy dog";

#define CHECK_DIGEST(algorithm, input, expected) \
	BOOST_CHECK(hash<algorithm>(input.c_str()) == expected); \
	BOOST_CHECK(hash<algorithm>(&input[0], input.size()) == expected); \
	BOOST_CHECK(hash<algorithm>(input.begin(), input.end()) == expected); \
	BOOST_CHECK(hash<algorithm>(input) == expected);

BOOST_AUTO_TEST_CASE(md2_hash_test) {
	CHECK_DIGEST(md2, empty_string, "8350e5a3e24c153df2275c9f80692773");
	CHECK_DIGEST(md2, lazy_dog,     "03d85a0d629d2c442e987525319fc471");
}

BOOST_AUTO_TEST_CASE(md5_hash_test) {
	CHECK_DIGEST(md5, empty_string, "d41d8cd98f00b204e9800998ecf8427e");
	CHECK_DIGEST(md5, lazy_dog,     "9e107d9d372bb6826bd81d3542a419d6");
}

BOOST_AUTO_TEST_CASE(sha_hash_test) {
	CHECK_DIGEST(sha, empty_string, "f96cea198ad1dd5617ac084a3d92c6107708c0ef");
	CHECK_DIGEST(sha, lazy_dog,     "b03b401ba92d77666221e843feebf8c561cea5f7");
}

BOOST_AUTO_TEST_CASE(sha1_hash_test) {
	CHECK_DIGEST(sha1, empty_string, "da39a3ee5e6b4b0d3255bfef95601890afd80709");
	CHECK_DIGEST(sha1, lazy_dog,     "2fd4e1c67a2d28fced849ee1bb76e7391b93eb12");
}

BOOST_AUTO_TEST_CASE(sha224_hash_test) {
	CHECK_DIGEST(sha224, empty_string, "d14a028c2a3a2bc9476102bb2882"
					   "34c415a2b01f828ea62ac5b3e42f");
	CHECK_DIGEST(sha224, lazy_dog,     "730e109bd7a8a32b1cb9d9a09aa2"
					   "325d2430587ddbc0c38bad911525");
}

BOOST_AUTO_TEST_CASE(sha256_hash_test) {
	CHECK_DIGEST(sha256, empty_string, "e3b0c44298fc1c149afbf4c8996fb924"
					   "27ae41e4649b934ca495991b7852b855");
	CHECK_DIGEST(sha256, lazy_dog,     "d7a8fbb307d7809469ca9abcb0082e4f"
					   "8d5651e46d3cdb762d02d0bf37c9e592");
}

BOOST_AUTO_TEST_CASE(sha384_hash_test) {
	CHECK_DIGEST(sha384, empty_string, "38b060a751ac96384cd9327eb1b1e36a21fdb71114be0743"
					   "4c0cc7bf63f6e1da274edebfe76f65fbd51ad2f14898b95b");
	CHECK_DIGEST(sha384, lazy_dog,     "ca737f1014a48f4c0b6dd43cb177b0afd9e5169367544c49"
					   "4011e3317dbf9a509cb1e5dc1e85a941bbee3d7f2afbc9b1");
}

BOOST_AUTO_TEST_CASE(sha512_hash_test) {
	CHECK_DIGEST(sha512, empty_string, "cf83e1357eefb8bdf1542850d66d8007d620e4050b5715dc83f4a921d36ce9ce"
					   "47d0d13c5d85f2b0ff8318d2877eec2f63b931bd47417a81a538327af927da3e");
	CHECK_DIGEST(sha512, lazy_dog,     "07e547d9586f6a73f73fbac0435ed76951218fb7d0c8d788a309d785436bbb64"
					   "2e93a252a954f23912547d1e8a3b5ed6e1bfd7097821233fa0538f3db854fee6");
}

BOOST_AUTO_TEST_CASE(hasher_test) {
	std::vector<std::string> input;
	input.push_back(empty_string);
	input.push_back(lazy_dog);

	std::vector<std::string> expected;
	expected.push_back("d41d8cd98f00b204e9800998ecf8427e");
	expected.push_back("9e107d9d372bb6826bd81d3542a419d6");

	std::vector<std::string> hashes;
	std::transform(input.begin(), input.end(), std::back_inserter(hashes), hasher<md5>());

	BOOST_CHECK_EQUAL_COLLECTIONS(hashes.begin(), hashes.end(), expected.begin(), expected.end());
}