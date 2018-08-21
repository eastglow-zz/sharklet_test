//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#ifndef SHARKLET_TESTTESTAPP_H
#define SHARKLET_TESTTESTAPP_H

#include "MooseApp.h"

class sharklet_testTestApp;

template <>
InputParameters validParams<sharklet_testTestApp>();

class sharklet_testTestApp : public MooseApp
{
public:
  sharklet_testTestApp(InputParameters parameters);
  virtual ~sharklet_testTestApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
  static void registerExecFlags(Factory & factory);
};

#endif /* SHARKLET_TESTTESTAPP_H */
