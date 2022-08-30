# get-next-line
Function that returns a line read from a descriptor file.
  
## Features
- Calling get_next_line repeatedly (for example, using a loop) allows you to read the contents of the file pointed to by the file descriptor, line by line, to the end.
- The function returns the line that was just read. If there is nothing more to read or if an error has occurred, it returns NULL.
- The returned line ends with `\n`, except if the end of the file has been reached and the file does not end with `\n`.
- The program is compiled with the `-D BUFFER_SIZE=xx` flag. This flag is used to determine the buffer size of `get_next_line()` reads.
- get_next_line is able to handle multiple fds at once using a single static variable
