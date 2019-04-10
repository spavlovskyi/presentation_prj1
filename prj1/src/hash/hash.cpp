#include "hash.hpp"
#include <openssl/evp.h>
#include <cassert>

namespace hash {

	std :: array < char, 64 > hexSha256 ( Bytes src ) {
		struct EVP_MD_CTX_deleter {
			void operator() ( EVP_MD_CTX * p ) const {
				EVP_MD_CTX_destroy ( p );
			}
		};
		std :: unique_ptr < EVP_MD_CTX, EVP_MD_CTX_deleter > p {
			EVP_MD_CTX_create ( )
		};
		auto check = [ ] ( int r ) {
			if ( r != 1 )
				throw std :: runtime_error { "file not found" };
		};
		check (
			EVP_DigestInit_ex (
				p.get ( ),
				EVP_sha256 ( ),
				nullptr
			)
		);
		check (
			EVP_DigestUpdate (
				p.get ( ),
				src.data ( ),
				src.size ( )
			)
		);
		auto constexpr digestSize = 32;
		assert ( digestSize == EVP_MD_CTX_size ( p.get ( ) ) && "wrong digest size" );
		std :: array < unsigned char, digestSize > digest;
		unsigned s = 0;
		check (
			EVP_DigestFinal_ex (
				p.get ( ),
				digest.data ( ),
				& s
			)
		);
		check ( s == digestSize );
		std :: array < char, digestSize * 2 > res;
		std :: size_t i = 0;
		for ( auto e : digest ) {
			static constexpr char syms [ ] = "0123456789abcdef";
			res [ i ++ ] = syms [ e >> 4 ];
			res [ i ++ ] = syms [ e & 0xf ];
		}
		return res;
	}

}
