#ifndef __ILLEGAL_BALANCE_EXCEPTION_H__
#define __ILLEGAL_BALANCE_EXCEPTION_H__

class IllegalBalanceException : public std::exception
{
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() noexcept = default;
    virtual const char *what() const noexcept {
        return "Cannot deposit illegal balance";
    }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
