#ifndef CORE_H
#define CORE_H

/// When rjff lib is compiles as static library
#ifdef RJFF_LIB_TYPE_STATIC

	#define RJFF_API

#else /// !RJFF_LIB_TYPE_STATIC

	#ifdef RJFF_LIB_EXPORT
	
		#define RJFF_API __declspec(dllexport)
	
	#else /// !RJFF_LIB_EXPORT
	
		#define RJFF_API __declspec(dllimport)
	
	#endif

#endif

#endif /// !CORE_H