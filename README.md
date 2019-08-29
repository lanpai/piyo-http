# piyoHTTP :love_letter: 🐦
a lightweight http server developed in c++

There are currently very limited features and security checks so PR's would be much appreciated.

**This is a hobby project which provides no guarantees to security. This software should not be used outside of a testing or development environment.**

Currently only available on Linux as this software follows POSIX standards for sockets using <sys/socket.h>

---

## 💽 Installation
- Clone the repository with `git clone https://github.com/lanpai/piyo-http.git`
- Compile the program with `make`
- And run the program using `make run` (does not currently support `make install`)

---

## 🚧 Roadmap
- v. **alpha**
  - [ ] Implement a scripting language
  - [ ] HTTPS support
  - [x] Multithreaded request handler
  - [ ] Multiplatform support
    - [x] Linux
    - [ ] Windows
    - [ ] MacOS

---

*Made with 💖 by lanpai*
