
## 😀 프로젝트 소개
The objective of this project is for you to create a simple shell. Yes, your own little bash or zsh. You will learn a lot about processes and file descriptors.
<p>
  <img width="500" src="https://user-images.githubusercontent.com/67721631/177960844-888d4980-d16c-45e6-bc8c-8e02bdec3af8.gif">
</p>

With Minishell, you’ll be able to travel through time and come back to problems people faced when Windows didn’t exist.

## 💻 사용언어
![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white) 

## 🗂︎ 사용패키지
ncurses Library
Termcap

## 🚘 설치방법 & 실행방법
```
git clone https://github.com/hopark123/minishell.git
make
./minishell
```
## 🛠 구현 내용
- bash commands : cd, pwd, env, exit, unset, export, echo (all other bash commands are implemented with execv)
- A working history: arrow key up/down
- Single and double Quotes
- Redirections: < (input), > (trunc), >> (append) and << (heredoc)
- Pipes: single and multible pipe(s), combination with redirections possible
- Environment Variables
- Signals: ctrl-C, ctrl-D and ctrl-\


