#pragma once

#include <stdlib.h>
#include <exception>
#include <string>
#include <sstream>

#define THROW( MSG)	throw std::exception( MSG);

template< template<int> class T, class U, int Enum>
struct Template
{
	static inline U* Switch(int e)
	{
		if (e == Enum)
			return T<Enum>::Exec();
		else
			return Template<T, U, Enum - 1>::Switch(e);
	}
};

template< template<int> class T, class U>
struct Template<T, U, 0>
{
	static inline U* Switch(int e)
	{
		if (e == 0)
			return T<0>::Exec();
		else
			THROW("the input enum doesn't exist.");
	}
};


//
template< template<int, int> class T, typename U,  int Enum1, int Enum2>
struct Template2
{

	static inline U* Switch( int e1, int e2)
	{
		if (e1 == Enum1)
			return Template2<T, U,  Enum1, Enum2>::Switch2( e2);
		else
			return Template2<T, U,  Enum1 - 1, Enum2>::Switch( e1, e2);
	}

private:
	template <template<int, int> class T, typename U,  int Enum1, int Enum2> friend struct Template2;

	static inline U* Switch2( int e2)
	{
		if (e2 == Enum2)
			return T<Enum1, Enum2>::Exec();
		else
			return Template2<T, U,  Enum1, Enum2 - 1>::Switch2( e2);
	}
};


template< template<int, int> class T, typename U,  int Enum2>
struct Template2<T, U,  0, Enum2>
{
	static inline U* Switch( int e1, int e2)
	{
		if (e1 == 0)
			return Template2<T, U,  0, Enum2>::Switch2( e2);
		else
			THROW("the input enum doesn't exist.");
	}

private:
	template <template<int, int> class T, typename U,  int Enum1, int Enum2> friend struct Template2;

	static inline U* Switch2( int e2)
	{
		if (e2 == Enum2)
			return T<0, Enum2>::Exec();
		else
			return Template2<T, U,  0, Enum2 - 1>::Switch2( e2);
	}
};


template< template<int, int> class T, typename U>
struct Template2<T, U,  0, 0>
{
	static inline U* Switch( int e1, int e2)
	{
		if ((e1 == 0) && (e2 == 0))
			return T<0, 0>::Exec();
		else
			THROW( "the input enum doesn't exist.");
	}

private:
	template <template<int, int> class T, typename U,  int Enum1, int Enum2> friend struct Template2;

	static inline U* Switch2( int e2)
	{
		if (e2 == 0)
			return T<0, 0>::Exec();
		else
			THROW( "the input enum doesn't exist.");
	}
};


template< template<int, int> class T, typename U,  int Enum1>
struct Template2<T, U,  Enum1, 0>
{
	static inline U* Switch( int e1, int e2)
	{
		if (e1 == Enum1)
			return Template2<T, U,  Enum1, 0>::Switch2( e2);
		else
			return Template2<T, U,  Enum1 - 1, 0>::Switch( e1, e2);
	}

private:
	template <template<int, int> class T, typename U,  int Enum1, int Enum2> friend struct Template2;

	static inline U* Switch2( int e2)
	{
		if (e2 == 0)
			return T<Enum1, 0>::Exec();
		else
			THROW( "the input enum doesn't exist.");
	}
};

////////
template< template<int, int, int> class T, typename U,  int Enum1, int Enum2, int Enum3>
struct Template3
{

	static inline U* Switch( int e1, int e2, int e3)
	{
		if (e1 == Enum1)
			return Template3<T, U,  Enum1, Enum2, Enum3>::Switch2( e2, e3);
		else
			return Template3<T, U,  Enum1 - 1, Enum2, Enum3>::Switch( e1, e2, e3);
	}

private:
	template <template<int, int, int> class T, typename U,  int Enum1, int Enum2, int Enum3> friend struct Template3;


	static inline U* Switch2( int e2, int e3)
	{
		if (e2 == Enum2)
			return Template3<T, U,  Enum1, Enum2, Enum3>::Switch3( e3);
		else
			return Template3<T, U,  Enum1, Enum2 - 1, Enum3>::Switch2( e2, e3);
	}


	static inline U* Switch3( int e3)
	{
		if (e3 == Enum3)
			return T<Enum1, Enum2, Enum3>::Exec();
		else
			return Template3<T, U,  Enum1, Enum2, Enum3 - 1>::Switch3( e3);
	}
};


template< template<int, int, int> class T, typename U,  int Enum1, int Enum2>
struct Template3<T, U,  Enum1, Enum2, 0>
{

	static inline U* Switch( int e1, int e2, int e3)
	{
		if (e1 == Enum1)
			return Template3<T, U,  Enum1, Enum2, 0>::Switch2( e2, e3);
		else
			return Template3<T, U,  Enum1 - 1, Enum2, 0>::Switch( e1, e2, e3);
	}

private:
	template <template<int, int, int> class T, typename U,  int Enum1, int Enum2, int Enum3> friend struct Template3;


	static inline U* Switch2( int e2, int e3)
	{
		if (e2 == Enum2)
			return Template3<T, U,  Enum1, Enum2, 0>::Switch3( e3);
		else
			return Template3<T, U,  Enum1, Enum2 - 1, 0>::Switch2( e2, e3);
	}


	static inline U* Switch3( int e3)
	{
		if (e3 == 0)
			return T<Enum1, Enum2, 0>::Exec();
		else
			THROW( "the input enum doesn't exist.");
	}
};



template< template<int, int, int> class T, typename U,  int Enum1>
struct Template3<T, U,  Enum1, 0, 0>
{

	static inline U* Switch( int e1, int e2, int e3)
	{
		if (e1 == Enum1)
			return Template3<T, U,  Enum1, 0, 0>::Switch2( e2, e3);
		else
			return Template3<T, U,  Enum1 - 1, 0, 0>::Switch( e1, e2, e3);
	}

private:
	template <template<int, int, int> class T, typename U,  int Enum1, int Enum2, int Enum3> friend struct Template3;


	static inline U* Switch2( int e2, int e3)
	{
		if (e2 == 0)
			return Template3<T, U,  Enum1, 0, 0>::Switch3( e3);
		else
			THROW( "the input enum doesn't exist.");
	}


	static inline U* Switch3( int e3)
	{
		if (e3 == 0)
			return T<Enum1, 0, 0>::Exec();
		else
			THROW( "the input enum doesn't exist.");
	}
};


template< template<int, int, int> class T, typename U>
struct Template3<T, U,  0, 0, 0>
{

	static inline U* Switch( int e1, int e2, int e3)
	{
		if (e1 == 0 && e2 == 0 && e3 == 0)
			return T<0, 0, 0>::Exec();
		else
			THROW( "the input enum doesn't exist.");
	}

private:
	template <template<int, int, int> class T, typename U,  int Enum1, int Enum2, int Enum3> friend struct Template3;


	static inline U* Switch2( int e2, int e3)
	{
		if (e2 == 0 && e3 == 0)
			return T<0, 0, 0>::Exec();
		else
			THROW( "the input enum doesn't exist.");
	}


	static inline U* Switch3( int e3)
	{
		if (e3 == 0)
			return T<0, 0, 0>::Exec();
		else
			THROW( "the input enum doesn't exist.");
	}
};


template< template<int, int, int> class T, typename U,  int Enum2>
struct Template3<T, U,  0, Enum2, 0>
{

	static inline U* Switch( int e1, int e2, int e3)
	{
		if (e1 == 0)
			return Template3<T, U,  0, Enum2, 0>::Switch2( e2, e3);
		else
			THROW( "the input enum doesn't exist.");
	}

private:
	template <template<int, int, int> class T, typename U,  int Enum1, int Enum2, int Enum3> friend struct Template3;


	static inline U* Switch2( int e2, int e3)
	{
		if (e2 == Enum2)
			return Template3<T, U,  0, Enum2, 0>::Switch3( e3);
		else
			return Template3<T, U,  0, Enum2 - 1, 0>::Switch2( e2, e3);
	}


	static inline U* Switch3( int e3)
	{
		if (e3 == 0)
			return T<0, Enum2, 0>::Exec();
		else
			THROW( "the input enum doesn't exist.");
	}
};


template< template<int, int, int> class T, typename U,  int Enum3>
struct Template3<T, U,  0, 0, Enum3>
{

	static inline U* Switch( int e1, int e2, int e3)
	{
		if (e1 == 0)
			return Template3<T, U,  0, 0, Enum3>::Switch2( e2, e3);
		else
			THROW( "the input enum doesn't exist.");
	}

private:
	template <template<int, int, int> class T, typename U,  int Enum1, int Enum2, int Enum3> friend struct Template3;


	static inline U* Switch2( int e2, int e3)
	{
		if (e2 == 0)
			return Template3<T, U,  0, 0, Enum3>::Switch3( e3);
		else
			THROW( "the input enum doesn't exist.");
	}


	static inline U* Switch3( int e3)
	{
		if (e3 == Enum3)
			return T<0, 0, Enum3>::Exec();
		else
			return Template3<T, U,  0, 0, Enum3 - 1>::Switch3( e3);
	}
};


template< template<int, int, int> class T, typename U,  int Enum1, int Enum3>
struct Template3<T, U,  Enum1, 0, Enum3>
{

	static inline U* Switch( int e1, int e2, int e3)
	{
		if (e1 == Enum1)
			return Template3<T, U,  Enum1, 0, Enum3>::Switch2( e2, e3);
		else
			return Template3<T, U,  Enum1 - 1, 0, Enum3>::Switch( e1, e2, e3);
	}

private:
	template <template<int, int, int> class T, typename U,  int Enum1, int Enum2, int Enum3> friend struct Template3;


	static inline U* Switch2( int e2, int e3)
	{
		if (e2 == 0)
			return Template3<T, U,  Enum1, 0, Enum3>::Switch3( e3);
		else
			THROW( "the input enum doesn't exist.");
	}


	static inline U* Switch3( int e3)
	{
		if (e3 == Enum3)
			return T<Enum1, 0, Enum3>::Exec();
		else
			return Template3<T, U,  Enum1, 0, Enum3 - 1>::Switch3( e3);
	}
};


template< template<int, int, int> class T, typename U,  int Enum2, int Enum3>
struct Template3<T, U,  0, Enum2, Enum3>
{

	static inline U* Switch( int e1, int e2, int e3)
	{
		if (e1 == 0)
			return Template3<T, U,  0, Enum2, Enum3>::Switch2( e2, e3);
		else
			THROW( "the input enum doesn't exist.");
	}

private:
	template <template<int, int, int> class T, typename U,  int Enum1, int Enum2, int Enum3> friend struct Template3;

	static inline U* Switch2( int e2, int e3)
	{
		if (e2 == Enum2)
			return Template3<T, U,  0, Enum2, Enum3>::Switch3( e3);
		else
			return Template3<T, U,  0, Enum2 - 1, Enum3>::Switch2( e2, e3);
	}

	static inline U* Switch3( int e3)
	{
		if (e3 == Enum3)
			return T<0, Enum2, Enum3>::Exec();
		else
			return Template3<T, U,  0, Enum2, Enum3 - 1>::Switch3( e3);
	}
};

//
template< template<int> class T, class U, int Enum1>
struct ClassSwitch
{
	static  U* Choose(int e1)
	{
		return Template<ChooseHelper, U, Enum1>::Switch(e1);
	}

protected:
	template<int Enum1>
	struct ChooseHelper
	{
		static U* Exec()
		{
			return new T<Enum1>();
		}
	};

};

template< template<int, int> class T, class U, int Enum1, int Enum2>
struct ClassSwitch2
{
	static  U* Choose(int e1, int e2)
	{
		return Template2<ChooseHelper, U, Enum1, Enum2>::Switch( e1, e2);
	}

protected:
	template<int Enum1, int Enum2>
	struct ChooseHelper
	{
		static U* Exec()
		{
			return new T<Enum1, Enum2>();
		}
	};
};

template< template<int, int, int> class T, class U, int Enum1, int Enum2, int Enum3>
struct ClassSwitch3
{
	static U* Choose(int e1, int e2, int e3)
	{
		return Template3<ChooseHelper, U, Enum1, Enum2, Enum3>::Switch(e1, e2, e3);
	}

protected:
	template<int Enum1, int Enum2, int Enum3>
	struct ChooseHelper
	{
		static U* Exec()
		{
			return new T<Enum1, Enum2, Enum3>();
		}
	};
};