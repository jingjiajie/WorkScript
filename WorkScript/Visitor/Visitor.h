#include "VisitResult.h"

namespace WorkScript{
    class Visitor{
    public:
        virtual VisitResult visitAssignment(Assignment *);
    };
}