<p align="center">
   <img src="https://partechpartners.com/media/images/holberton-logo-web.original.png" alt="logo HS">
</p>

# Simple Shell

This is a UNIX command interpreter which is based on sh

### Table of Contents

* [Description](#Description)
* [Files](#Files-in-this-repository)
* [Installation](#Installation)
* [Usage](#Usage)
* [How it works](#How-it-works)
* [Authors](#Authors)

### Description

 This is a simple representation of what sh does, sh is a command language interpreter that executes commands read from a command line string, the standar input, or a specified file

### Files in this repository

File | Description
--- | ---
`shell.h` | Header file
`shell.c` | Main file
`str_funcs.c` | String functions implemented
`pointer_funcs.c` | Control of pointer related functions
`env_funcs.c` | Environment functions
`control_funcs.c` | Control of the output for different scenarios

### Installation

First of all clone this repository: `git clone https://github.com/BrianFs04/simple_shell.git` then you need to compile it using this command `gcc -Wall -Werror -Wextra -pedantic *.c -o shell`

### Usage

This shell works in both interactive and non-interactive mode, you can execute it in the following ways

Example in interactive mode
```
$ ./shell
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
Example in non-interactive mode
```
$ echo "/bin/ls" | ./shell
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./shell
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

### How it works

After compiling. Run the executable in the following way `./shell`

This simple shell displays a prompt `#cisfun$ ` and wait for the user to type a command which always ends with a new line
```
#cisfun$ /bin/ls
control_funcs.c  env_funcs.c  pointer_funcs.c  README.md  shell  shell.c  shell.h  str_funcs.c
```
The prompt `#cisfun$ ` is displayed again each time a command has been executed

You can also handle commands lines with arguments
```
#cisfun$ ls -l
total 44
-rw-rw-r-- 1 vagrant vagrant   882 Nov 28 00:07 control_funcs.c
-rw-rw-r-- 1 vagrant vagrant  1257 Nov 28 00:44 env_funcs.c
-rw-rw-r-- 1 vagrant vagrant  1378 Nov 28 00:52 pointer_funcs.c
-rw-rw-r-- 1 vagrant vagrant  2106 Nov 28 01:35 README.md
-rwxrwxr-x 1 vagrant vagrant 14064 Nov 28 00:52 shell
-rw-rw-r-- 1 vagrant vagrant   889 Nov 28 00:03 shell.c
-rw-rw-r-- 1 vagrant vagrant   862 Nov 28 00:52 shell.h
-rw-rw-r-- 1 vagrant vagrant  1122 Nov 28 00:29 str_funcs.c
```
Is is capable also of handling the `PATH`
```
#cisfun$ ls -l /usr
total 60
drwxr-xr-x   2 root root 32768 Oct 25 22:31 bin
drwxr-xr-x   2 root root  4096 Apr 10  2014 games
drwxr-xr-x  35 root root  4096 Oct 18 14:24 include
drwxr-xr-x  73 root root  4096 Oct  2 19:23 lib
drwxr-xr-x  10 root root  4096 May 14  2019 local
drwxr-xr-x   2 root root  4096 Oct  2 19:23 sbin
drwxr-xr-x 134 root root  4096 Oct 16 16:25 share
drwxr-xr-x   4 root root  4096 Oct  2 19:23 src

```
You can also print the environment in this simple shell by typing `env`
```
#cisfun$ env
USER=vagrant
LOGNAME=vagrant
HOME=/home/vagrant
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games
MAIL=/var/mail/vagrant
SHELL=/usr/bin/zsh
SSH_CLIENT=10.0.2.2 54947 22
SSH_CONNECTION=10.0.2.2 54947 10.0.2.15 22
SSH_TTY=/dev/pts/0
TERM=xterm
XDG_SESSION_ID=2
XDG_RUNTIME_DIR=/run/user/1000
LANG=en_US.UTF-8
SHLVL=1
PWD=/home/vagrant/works
OLDPWD=/home/vagrant/tests_shell
ZSH=/home/vagrant/.oh-my-zsh
PAGER=less
LESS=-R
LSCOLORS=Gxfxcxdxbxegedabagacad
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arj=01;31:*.taz=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.zip=01;31:*.z=01;31:*.Z=01;31:*.dz=01;31:*.gz=01;31:*.lz=01;31:*.xz=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.jpg=01;35:*.jpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.axv=01;35:*.anx=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.axa=00;36:*.oga=00;36:*.spx=00;36:*.xspf=00;36:
_=/home/vagrant/works/./shell
```

If you want to exit this shell you can use either `Ctrl+D` or `exit`

---

### Authors

Brian Florez [GitHub](https://github.com/BrianFs04)
David Ovalle [GitHub](https://github.com/Nukemenonai)