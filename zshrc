export PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/homebrew/bin:/opt/homebrew/bin -
alias python=python3
PS1='%B%F{blue}%*%f%b %B%F{blue}%1~$ %f%b'
echo -e "\033[1;32m" 
alias ls=ls -G
make() {
    c++ -I$HOME/compilar "$1.cpp" -std=c++17 -o "$1" 
    if [[ $? -eq 0 ]]; then
        echo "\033[1;32mCompilou\033[0m"
		./"$1"
    else
        echo "\033[1;31mFalhou\033[0m"
    fi
}

open() {
	touch "$1".cpp
	cp ~/Desktop/Lib-das-lindas/template.cpp "$1".cpp
	vim "$1".cpp
}


