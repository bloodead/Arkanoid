int  write(  int  handle,  void  *buffer,  int  nbyte  );

void id_print_char(char c);

void id_print_char(char c)
{

 write(1,&c,1);

}

