/******************************************************************************
* Turbo C++11 metaprogramming Library                                         *
*                                                                             *
* Copyright (C) 2013 - 2014, Manuel Sánchez Pérez                             *
*                                                                             *
* This file is part of The Turbo Library.                                     *
*                                                                             *
* The Turbo Library is free software: you can redistribute it and/or modify   *
* it under the terms of the GNU Lesser General Public License as published by *
* the Free Software Foundation, version 2 of the License.                     *
*                                                                             *
* The Turbo Library is distributed in the hope that it will be useful,        *
* but WITHOUT ANY WARRANTY; without even the implied warranty of              * 
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
* GNU Lesser General Public License for more details.                         *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with The Turbo Library. If not, see <http://www.gnu.org/licenses/>.   *
******************************************************************************/

#include "eval.hpp"
#include "placeholders.hpp"
#include "let_expressions.hpp"

#include "lazy.hpp"
#include "lambda.hpp"

#include "integral_lists.hpp"

#include "basic_types.hpp"
#include "utils/assert.hpp"

using namespace tml::placeholders;

template<typename... ARGS>
struct f
{
    using result = tml::list<ARGS...>;
};


using t1 = tml::eval<Int<0>>;
using t2 = tml::eval<f<_1,_2,_3>,Int<1>,Int<2>,Int<3>>;
using t3 = tml::eval<tml::lazy<f>,Int<1>,Int<2>,Int<3>>; 
using t4 = tml::eval<tml::lambda<_1,f<_1,Int<2>,Int<3>>>,Int<1>>;
using t5 = tml::eval<tml::multi_let<_1,_2,_3,Int<1>,Int<2>,Int<3>,f<_1,_2,_3>>>;
using t6 = tml::eval<tml::multi_lambda<f<_1,_2,_3>,_1,_2,_3>,Int<1>,Int<2>,Int<3>>;




TURBO_ASSERT((std::is_same<t1,tml::integer<0>>));
TURBO_ASSERT((std::is_same<t2,tml::integer_list<1,2,3>>));
TURBO_ASSERT((std::is_same<t3,tml::integer_list<1,2,3>>));
TURBO_ASSERT((std::is_same<t4,tml::integer_list<1,2,3>>));
TURBO_ASSERT((std::is_same<t5,tml::integer_list<1,2,3>>));
TURBO_ASSERT((std::is_same<t6,tml::integer_list<1,2,3>>));


int main(){}