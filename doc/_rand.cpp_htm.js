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
'other.htm',
'rand.htm',
'rand.cpp.htm'
];
var list_down4 = [
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
var list_down3 = [
'elementwise.htm',
'matrixwise.htm',
'scalar_valued.htm',
'other.htm'
];
var list_down2 = [
'extend.htm',
'ones.htm',
'rand.htm',
'randn.htm',
'size.htm',
'slice.htm',
'zeros.htm'
];
var list_down1 = [
'rand.cpp.htm'
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
function choose_down4(item)
{	var index          = item.selectedIndex;
	item.selectedIndex = 0;
	if(index > 0)
		document.location = list_down4[index-1];
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
