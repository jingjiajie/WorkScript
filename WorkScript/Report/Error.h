#pragma once
#include "ReportItem.h"

#define WS_ERROR_COMMON_DECL(CLASS_NAME) \
class CLASS_NAME : public Error { public: using Error::Error; };

namespace WorkScript
{
    class Error : public ReportItem
    {
    public:
        using ReportItem::ReportItem;
    };

    WS_ERROR_COMMON_DECL(AccessDeniedError)

    WS_ERROR_COMMON_DECL(DuplicateDeclarationError)

    WS_ERROR_COMMON_DECL(IllegalValueError)

    WS_ERROR_COMMON_DECL(UnassignableError)

    WS_ERROR_COMMON_DECL(UncalculatableError)

    WS_ERROR_COMMON_DECL(UncomparableError)

    WS_ERROR_COMMON_DECL(UnimplementedError)

    WS_ERROR_COMMON_DECL(UninvocableError)

    WS_ERROR_COMMON_DECL(UndefinedSymbolError)

    WS_ERROR_COMMON_DECL(TypeNotFoundError)

    WS_ERROR_COMMON_DECL(TypeMismatchedError)

    WS_ERROR_COMMON_DECL(IncompatibleTypeError)

    WS_ERROR_COMMON_DECL(UninferableTypeError)

    WS_ERROR_COMMON_DECL(SyntaxError)
}