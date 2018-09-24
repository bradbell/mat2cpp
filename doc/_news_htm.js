var list_across0 = [
'_contents.htm',
'_reference.htm',
'_index.htm',
'_search.htm',
'_external.htm'
];
var list_up0 = [
'mat2cpp.htm',
'news.htm'
];
var list_down1 = [
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
var list_current0 = [
'news.htm#2013-07-25',
'news.htm#2013-07-20',
'news.htm#06-05-15',
'news.htm#06-05-05',
'news.htm#06-04-18'
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
