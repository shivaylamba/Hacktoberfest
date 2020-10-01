Program multiplication_table_sum;
uses crt;
var
   num, sum, cont : integer;
   resp : char;
Begin
   resp := 'S';
   while (upcase(resp) = 'S') do begin
      clrscr;
      writeln('Multiplication table generator');
      write('Insert table number');
      readln(num);
      cont := 1;
      sum := 0;
      while (cont <= 10) do begin
         writeln(cont, ' X ', num, ' = ', cont * num );
         sum := sum + cont * num;
   	    cont := cont + 1
      end;
      writeln('----------------------------');
      writeln('Final sum: ', sum);
      writeln('');
      write('New number? '); readln(resp);
   end;
End.
