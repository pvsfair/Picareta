#include "Utensilio.h"

Utensilio::Utensilio(int maxRes, float atualRes)
{
    const_cast<&int>(this->maxRes) = maxRes;
}

Utensilio::~Utensilio()
{
}

