var list_across0 = [
'_contents.htm',
'_reference.htm',
'_index.htm',
'_search.htm',
'_external.htm'
];
var list_up0 = [
'mat2cpp.htm',
'operation.htm',
'matrixwise.htm',
'diag_prod.htm'
];
var list_down3 = [
'license.htm',
'getstarted.htm',
'operation.htm',
'mat2cpp.hpp.htm',
'mat2cpp_ok.m.htm',
'mat2cpp_ok.cpp.htm',
'news.htm',
'library.htm',
'mztuni.htm'
];
var list_down2 = [
'elementwise.htm',
'matrixwise.htm',
'scalar_valued.htm',
'other.htm'
];
var list_down1 = [
'diag_prod.htm',
'cholesky.htm',
'matrix_div.htm',
'matrix_prod.htm',
'transpose.htm'
];
var list_down0 = [
'diag_prod.cpp.htm'
];
var list_current0 = [
'diag_prod.htm#Syntax',
'diag_prod.htm#Matlab or Octave',
'diag_prod.htm#Matlab or Octave.Example',
'diag_prod.htm#C++',
'diag_prod.htm#C++.Example',
'diag_prod.htm#C++.Source'
];
function choose_across0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_across0[index-1];
}
function choose_up0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_up0[index-1];
}
function choose_down3(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down3[index-1];
}
function choose_down2(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down2[index-1];
}
function choose_down1(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down1[index-1];
}
function choose_down0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down0[index-1];
}
function choose_current0(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_current0[index-1];
}
