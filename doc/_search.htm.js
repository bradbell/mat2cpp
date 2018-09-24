// ------------------------------------------------------------ 
// Copyright (C) Bradley M. Bell 1998-2015, All rights reserved 
// ------------------------------------------------------------ 
Keyword = 
[
'mat2cpp  Example Conversion of Matlab or Octave to C++ using Ublas  ',' library link ',
'License  The mat2cpp Software License  ',' ',
'getstarted  Getting Started  ',' output matrix ',
'operation  Operations That Have Conversions  ',' ',
'elementwise  Elementwise Operations  ',' ',
'add  Elementwise Addition  ',' ',
'element_div  Elementwise Division  ',' ',
'element_prod  Elementwise Product  ',' ',
'element_unary  Matlab or Octave Elementwise Unary Functions  ',' math ',
'element_unary.cpp  Elementwise Unary Functions Source Code  ',' ',
'scalar_div  Scalar Division  ',' ',
'scalar_prod  Scalar Product  ',' ',
'sub  Elementwise Subtraction  ',' ',
'matrixwise  Matrixwise Operations  ',' ',
'diag_prod  Diagonal Matrix Product with General Matrix  ',' ',
'diag_prod.cpp  Diagonal Matrix Product with General Matrix Source Code  ',' ',
'cholesky  Cholesky Factor a Matrix Division  ',' ',
'cholesky.cpp  Cholesky Factor a Matrix Source Code  ',' ',
'matrix_div  Matrix Division  ',' ',
'matrix_div.cpp  Matrix Division Source Code  ',' ',
'matrix_prod  Matrix Product  ',' multiply times ',
'transpose  Matrix Transpose  ',' ',
'scalar_valued  Scalar Valued Operations  ',' ',
'max  Maximum Element of a Matrix  ',' ',
'max.cpp  Maximum Element of a Matrix Source code  ',' ',
'min  Minimum Element of a Matrix  ',' ',
'min.cpp  Minimum Element of a Matrix Source Code  ',' ',
'scalar  Convert Matrix to Scalar  ',' ',
'scalar.cpp  Convert Matrix to Scalar Source Code  ',' ',
'sum  Sum The Elements of a Matlab  ',' ',
'sum.cpp  Sum The Elements of a Matlab Source Code  ',' ',
'other  Other Operations  ',' ',
'extend  Extending a Vector  ',' ',
'ones  Matrix of Ones  ',' ',
'rand  Uniform Random Matrix  ',' ',
'rand.cpp  Uniform Random Matrix Source Code  ',' ',
'randn  Normal Random Matrix  ',' simulate gaussian ',
'randn.cpp  Normal Random Matrix Source Code  ',' ',
'size  Matrix Size  ',' ',
'slice  Matrix Slices  ',' sub-matrix ',
'zeros  Matrix of Zeros  ',' ',
'mat2cpp.hpp  The Matlab or Octave to C++ Using Ublas Include File  ',' ',
'mat2cpp_ok.m  Run Matlab or Octave Version of Examples  ',' ',
'mat2cpp_ok.cpp  Run C++ Version of Examples  ',' ',
'News  The mat2cpp News file  ',' ',
'library  Adding a New Routine to the Mat2cpp Library  ',' ',
'mztuni  C++ Marsaglia Zaman Tsang Uniform Random Number Generator  ',' typo ',
'mztuni_ok.cpp  mztuni: Example and Test  ',' ',
'mztuni.cpp  C++ Marsaglia Zaman Tsang Uniform Random Number Source Code  ',' '
]

var MaxList = 100;
var Nstring = -1;
var Nkeyword = Keyword.length / 2;
Initialize();

function Initialize()
{
	UpdateList();
	document.search.keywords.focus();
}
function UpdateList(event)
{
	key = 0;
	if( window.event )
		key = window.event.keyCode;
	else if( event )
		key = event.which;
	if( key == 13 )
	{	Goto();
		return;
	}
	var string  = document.search.keywords.value;
	if( Nstring == string.length )
		return;
	Nstring     = string.length;

	var word    = string.match(/\S+/g);
	var nword   = 0;
	if(word != null )
		nword   = word.length;

	var pattern = new Array(nword);
	for(var j = 0; j < nword; j++)
		pattern[j] = new RegExp(word[j], 'i');

	var nlist = 0;
	var list  = '';
	for(i = 0; (i < Nkeyword) && (nlist < MaxList) ; i++)
	{
		var match = true;
		for(j = 0; j < nword; j++)
		{	var flag = pattern[j].test(Keyword[2*i]);
			flag     = flag || pattern[j].test(Keyword[2*i+1]);
			match    = match && flag;
		}

		if( match )
		{
			line  = Keyword[2*i].split(/\s+/);
			line  = line.join(' ');
			list  = list + line + '\n';
			nlist = nlist + 1;
		}
	}
	document.search.list.value    = list;
}
function Choose(textarea)
{	var start_select = textarea.value.substring(0, textarea.selectionStart);
	var start_pos    = Math.max(0, start_select.lastIndexOf('\n') );
	var length       = textarea.value.length;
	var end_select   = 
		textarea.value.substring(textarea.selectionEnd, length);
	var end_pos      = end_select.indexOf('\n');
	if( end_pos >= 0 ) 
	{	end_pos = textarea.selectionEnd + end_pos;
	} else 
	{	end_pos = length;
	}
	// highlight the selected line
	textarea.selectionStart = start_pos;
	textarea.selectionEnd   = end_pos;
	// get the choice from the beginning of the line
	var line = textarea.value.substring(start_pos, length);
	var end_choice = line.indexOf(' ');
	if( end_choice >= 0 )
	{	var choice = line.substring(0, end_choice);
		document.search.choice.value = choice.toLowerCase();
	}
	
	return true;
}
function Goto()
{
parent.location = document.search.choice.value + '.htm';
}
