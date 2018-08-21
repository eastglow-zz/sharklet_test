//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "sharklet_testTestApp.h"
#include "sharklet_testApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

template <>
InputParameters
validParams<sharklet_testTestApp>()
{
  InputParameters params = validParams<sharklet_testApp>();
  return params;
}

sharklet_testTestApp::sharklet_testTestApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  sharklet_testApp::registerObjectDepends(_factory);
  sharklet_testApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  sharklet_testApp::associateSyntaxDepends(_syntax, _action_factory);
  sharklet_testApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  sharklet_testApp::registerExecFlags(_factory);

  bool use_test_objs = getParam<bool>("allow_test_objects");
  if (use_test_objs)
  {
    sharklet_testTestApp::registerObjects(_factory);
    sharklet_testTestApp::associateSyntax(_syntax, _action_factory);
    sharklet_testTestApp::registerExecFlags(_factory);
  }
}

sharklet_testTestApp::~sharklet_testTestApp() {}

void
sharklet_testTestApp::registerApps()
{
  registerApp(sharklet_testApp);
  registerApp(sharklet_testTestApp);
}

void
sharklet_testTestApp::registerObjects(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new test objects here! */
}

void
sharklet_testTestApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
  /* Uncomment Syntax and ActionFactory parameters and register your new test objects here! */
}

void
sharklet_testTestApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execute flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
sharklet_testTestApp__registerApps()
{
  sharklet_testTestApp::registerApps();
}

// External entry point for dynamic object registration
extern "C" void
sharklet_testTestApp__registerObjects(Factory & factory)
{
  sharklet_testTestApp::registerObjects(factory);
}

// External entry point for dynamic syntax association
extern "C" void
sharklet_testTestApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  sharklet_testTestApp::associateSyntax(syntax, action_factory);
}

// External entry point for dynamic execute flag loading
extern "C" void
sharklet_testTestApp__registerExecFlags(Factory & factory)
{
  sharklet_testTestApp::registerExecFlags(factory);
}
