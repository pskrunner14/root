// @(#)root/reflex:$Name:  $:$Id: TypedefBuilder.cxx,v 1.9 2006/08/03 16:49:21 roiser Exp $
// Author: Stefan Roiser 2004

// Copyright CERN, CH-1211 Geneva 23, 2004-2006, All rights reserved.
//
// Permission to use, copy, modify, and distribute this software for any
// purpose is hereby granted without fee, provided that this copyright and
// permissions notice appear in all copies and derivatives.
//
// This software is provided "as is" without express or implied warranty.

#ifndef REFLEX_BUILD
#define REFLEX_BUILD
#endif

#include "Reflex/Builder/TypedefBuilder.h"
#include "Reflex/Builder/TypeBuilder.h"

#include "Typedef.h"

#include "Reflex/internal/OwnedMember.h"


//-------------------------------------------------------------------------------
ROOT::Reflex::TypedefBuilderImpl::TypedefBuilderImpl( const char * typ,
                                                      const Type & typedefType ) {
//-------------------------------------------------------------------------------
// Construct typedef info.
   fTypedef = TypedefTypeBuilder( typ, typedefType );
}


//-------------------------------------------------------------------------------
void ROOT::Reflex::TypedefBuilderImpl::AddProperty( const char * key,
                                                    Any value ) {
//-------------------------------------------------------------------------------
// Attach a property to this typedef as Any object.
   fTypedef.Properties().AddProperty( key, value );
}


//-------------------------------------------------------------------------------
void ROOT::Reflex::TypedefBuilderImpl::AddProperty( const char * key,
                                                    const char * value ) {
//-------------------------------------------------------------------------------
// Attach a property to this typedef as string.
   AddProperty( key, Any(value));
}

