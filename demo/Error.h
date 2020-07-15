#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <exception>

namespace rj {

	/// Declarations

	template<class Function, class ...Args>
	bool tryCatchAndPrint(const Function &function, Args ... args);



	/// Definitions

	template<class Function, class ...Args>
	inline bool tryCatchAndPrint(const Function & function, Args ...args)
	{
		try {
			//function(args);
			function();
		}
		catch (std::exception ex) {
			std::cout << ex.what() << '\n';
			return false;
		}

		return true;
	}

}

#endif /// !ERROR_H
