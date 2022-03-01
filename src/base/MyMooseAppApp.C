#include "MyMooseAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MyMooseAppApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

MyMooseAppApp::MyMooseAppApp(InputParameters parameters) : MooseApp(parameters)
{
  MyMooseAppApp::registerAll(_factory, _action_factory, _syntax);
}

MyMooseAppApp::~MyMooseAppApp() {}

void
MyMooseAppApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"MyMooseAppApp"});
  Registry::registerActionsTo(af, {"MyMooseAppApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MyMooseAppApp::registerApps()
{
  registerApp(MyMooseAppApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MyMooseAppApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MyMooseAppApp::registerAll(f, af, s);
}
extern "C" void
MyMooseAppApp__registerApps()
{
  MyMooseAppApp::registerApps();
}
