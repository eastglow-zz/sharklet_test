#include "sharklet_testApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template <>
InputParameters
validParams<sharklet_testApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

sharklet_testApp::sharklet_testApp(InputParameters parameters) : MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  sharklet_testApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  sharklet_testApp::associateSyntax(_syntax, _action_factory);

  Moose::registerExecFlags(_factory);
  ModulesApp::registerExecFlags(_factory);
  sharklet_testApp::registerExecFlags(_factory);
}

sharklet_testApp::~sharklet_testApp() {}

void
sharklet_testApp::registerApps()
{
  registerApp(sharklet_testApp);
}

void
sharklet_testApp::registerObjects(Factory & factory)
{
    Registry::registerObjectsTo(factory, {"sharklet_testApp"});
}

void
sharklet_testApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & action_factory)
{
  Registry::registerActionsTo(action_factory, {"sharklet_testApp"});

  /* Uncomment Syntax parameter and register your new production objects here! */
}

void
sharklet_testApp::registerObjectDepends(Factory & /*factory*/)
{
}

void
sharklet_testApp::associateSyntaxDepends(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}

void
sharklet_testApp::registerExecFlags(Factory & /*factory*/)
{
  /* Uncomment Factory parameter and register your new execution flags here! */
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
sharklet_testApp__registerApps()
{
  sharklet_testApp::registerApps();
}

extern "C" void
sharklet_testApp__registerObjects(Factory & factory)
{
  sharklet_testApp::registerObjects(factory);
}

extern "C" void
sharklet_testApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
  sharklet_testApp::associateSyntax(syntax, action_factory);
}

extern "C" void
sharklet_testApp__registerExecFlags(Factory & factory)
{
  sharklet_testApp::registerExecFlags(factory);
}
