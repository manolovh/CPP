#ifndef _INSUFFICIENT_FUNDS_EXCEPTION_H__
#define _INSUFFICIENT_FUNDS_EXCEPTION_H__

class InsufficientFundsException : public std::exception
{
public:
    InsufficientFundsException() noexcept = default;
    ~InsufficientFundsException() noexcept = default;
    virtual const char *what() const noexcept {
        return "Failed to withdraw unavailable funds.";
    }
};

#endif // __ILLEGAL_BALANCE_EXCEPTION_H__
