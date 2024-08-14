#ifndef ERROR_H
#define ERROR_H

#define ILLEGALPARAM(name) warn("illegal param: %s", name)
#define NULLOBJ(name) warn("null object: %s", name)
#define OBJNOTFOUND(name) warn("obj %s not found", name)
#define ILLEGALSTATE(why) warn("illegal state: %s", why)

#define IOERROR(filename) error("ioerror on file %s", filename); exit(SIGIO);
#define ABORT(param) error(param); exit(SIGABRT);

#endif
