#include <hash/fipsmode.hpp>
#include <hash/hash.hpp>
#include <fstream>
#include <iostream>

int main ( int argc, const char * const argv [ ] ) {
	if ( argc != 2 ) {
		std :: cerr << "usage: " << argv [ 0 ] << " filename\n";
		return EXIT_FAILURE;
	}
	hash :: enableFipsMode ( );
	std :: ifstream is {
		argv [ 1 ],
		std :: ios :: binary
	};
	if ( ! is ) {
		std :: cerr << "can't open file\n";
		return EXIT_FAILURE;
	}
	std :: array < char, 1024 > buf;
	is.read ( buf.data ( ), buf.size ( ) );
	if ( ! is && ! is.eof ( ) ) {
		std :: cerr << "error reading file\n";
		return EXIT_FAILURE;
	}
	hash :: Bytes src = as_bytes (
		gsl :: make_span (
			buf.data ( ),
			is.gcount ( )
		)
	);
	auto digest = hash :: hexSha256 ( src );
	std :: cout.write ( digest.data ( ), digest.size ( ) ).put ( '\n' );
	return std :: cout ? EXIT_SUCCESS : EXIT_FAILURE;
}
