@license{
	Copyright (c) 2014, Ernesto C. B. de Matos, Anamaria M. Moreira, João B. de S. Neto.
	All rights reserved.
	
	Redistribution and use in source and binary forms, with or without modification, are permitted provided that 
	the following conditions are met:
	
	1. Redistributions of source code must retain the above copyright notice, this list of conditions and the 
		following disclaimer.
	
	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the 
		following disclaimer in the documentation and/or other materials provided with the distribution.
	
	3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote 
		products derived from this software without specific prior written permission.
	
	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
	INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
	DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
	SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
	WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE 
	USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
}
@contributor{João Batista de Souza Neto}

@doc{

Synopsis: Functions that translate B predicates and expressions to C expressions.

}

module B::CTranslate

import B::Syntax;
import String;
import ParseTree;
import IO;

public str translate(str txt) = translatePred(parse(#Predicate, txt));
//public str translate(str txt) = translatePred("", parse(#Predicate, txt));

public str translatePred((Predicate) `(<Predicate p>)`) = "(<translatePred( p)>)";
public str translatePred((Predicate) `not(<Predicate p>)`) = "!(<translatePred( p)>)";
public str translatePred((Predicate) `<Predicate p1>&<Predicate p2>`) = "<translatePred( p1)> && <translatePred( p2)>";
public str translatePred((Predicate) `<Predicate p1>or<Predicate p2>`) = "<translatePred( p1)> || <translatePred( p2)>";
public str translatePred((Predicate) `<Predicate p1>=\><Predicate p2>`) = "!(<translatePred( p1)>) || <translatePred( p2)>";
public str translatePred((Predicate) `<Predicate p1>\<=\><Predicate p2>`) = "(<translatePred( p1)> && <translatePred( p2)>) || !(<translatePred( p1)> || <translatePred( p2)>)";
public str translatePred((Predicate) `<Expression e1>=<Expression e2>`) = "<translateExp(e1)> == <translateExp(e2)>";
public str translatePred((Predicate) `<Expression e1>/=<Expression e2>`) = "<translateExp(e1)> != <translateExp(e2)>";
public str translatePred((Predicate) `<Expression e1>\<=<Expression e2>`) = "<translateExp(e1)> \<= <translateExp(e2)>";
public str translatePred((Predicate) `<Expression e1>\<<Expression e2>`) = "<translateExp(e1)> \< <translateExp(e2)>";
public str translatePred((Predicate) `<Expression e1>\>=<Expression e2>`) = "<translateExp(e1)> \>= <translateExp(e2)>";
public str translatePred((Predicate) `<Expression e1>\><Expression e2>`) = "<translateExp(e1)> \> <translateExp(e2)>";
public str translatePred((Predicate) `<Expression e1>:<Expression e2>`) {
	if((Expression) `<Expression i1>..<Expression i2>` := e2){
		return "<translateExp(e1)> \>= <translateExp(i1)> && <translateExp(e1)> \<= <translateExp(i2)>";	
	} else {
		return "";
	}
}
public default str translatePred( Predicate p) = "";

public str translateExp((Expression) `<Ident id>`) = "<id>";

public str translateExp((Expression) `(<Expression e>)`) = "(<translateExp( e)>)";

public str translateExp((Expression) `TRUE`) = "true";
public str translateExp((Expression) `FALSE`) = "false";
public str translateExp((Expression) `bool(<Predicate p>)`) = translatePred( p);

public str translateExp((Expression) `<Integer_literal i>`) = "<i>";
public str translateExp((Expression) `MAXINT`) = "INT32_MAX";
public str translateExp((Expression) `MININT`) = "INT32_MIN";

public str translateExp((Expression) `<Expression e1>+<Expression e2>`) = "<translateExp(e1)> + <translateExp(e2)>";
public str translateExp((Expression) `<Expression e1>-<Expression e2>`) = "<translateExp(e1)> - <translateExp(e2)>";
public str translateExp((Expression) `-<Expression e>`) = "-<translateExp( e)>";
public str translateExp((Expression) `<Expression e1>*<Expression e2>`) = "<translateExp(e1)> * <translateExp(e2)>";
public str translateExp((Expression) `<Expression e1>/<Expression e2>`) = "<translateExp(e1)> / <translateExp(e2)>";
public str translateExp((Expression) `<Expression e1>mod<Expression e2>`) = "<translateExp(e1)> % <translateExp(e2)>";
public str translateExp((Expression) `<Expression e1>**<Expression e2>`) = "pow(<translateExp(e1)>, <translateExp(e2)>)";
public str translateExp((Expression) `succ(<Expression e>)`) = "(<translateExp( e)> + 1)";
public str translateExp((Expression) `pred(<Expression e>)`) = "(<translateExp( e)> - 1)";

public str translateExp((Expression) `<Expression e1>|-\><Expression e2>`) = "<translateExp(e2)>";

public default str translateExp(Expression e) = "<e>";