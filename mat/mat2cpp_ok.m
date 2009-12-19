% $begin mat2cpp_ok.m$$ $newlinech %$$
% $spell
%	cholesky
%	Matlab
%	div
%	mat2cpp
%	feval
%	randn
% $$
%
% $section Run Matlab or Octave Version of Examples$$
%
% $codep
function mat2cpp_ok()
ok   = true;
ok   = ok & run_test('add_ok');
ok   = ok & run_test('cholesky_ok');
ok   = ok & run_test('diag_prod_ok');
ok   = ok & run_test('element_div_ok');
ok   = ok & run_test('element_prod_ok');
ok   = ok & run_test('element_unary_ok');
ok   = ok & run_test('extend_ok');
ok   = ok & run_test('matrix_div_ok');
ok   = ok & run_test('matrix_prod_ok');
ok   = ok & run_test('max_ok');
ok   = ok & run_test('min_ok');
ok   = ok & run_test('ones_ok');
ok   = ok & run_test('rand_ok');
ok   = ok & run_test('randn_ok');
ok   = ok & run_test('scalar_div_ok');
ok   = ok & run_test('scalar_prod_ok');
ok   = ok & run_test('size_ok');
ok   = ok & run_test('slice_ok');
ok   = ok & run_test('sub_ok');
ok   = ok & run_test('sum_ok');
ok   = ok & run_test('transpose_ok');
ok   = ok & run_test('zeros_ok');
if ok
	'All tests passed'
else
	'At least one test failed'
end
return
% ------------------------------------
function [ok] = run_test(test_name)
ok = feval(test_name);
if( ok )
	['ok:    ', test_name]
else
	['error: ', test_name]
end
return
% $$
%
% $end
