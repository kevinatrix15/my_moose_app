//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MyMooseAppTestApp.h"
#include "MyMooseAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
MyMooseAppTestApp::validParams()
{
  InputParameters params = MyMooseAppApp::validParams();
  return params;
}

MyMooseAppTestApp::MyMooseAppTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MyMooseAppTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MyMooseAppTestApp::~MyMooseAppTestApp() {}

void
MyMooseAppTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MyMooseAppApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MyMooseAppTestApp"});
    Registry::registerActionsTo(af, {"MyMooseAppTestApp"});
  }
}

void
MyMooseAppTestApp::registerApps()
{
  registerApp(MyMooseAppApp);
  registerApp(MyMooseAppTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MyMooseAppTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MyMooseAppTestApp::registerAll(f, af, s);
}
extern "C" void
MyMooseAppTestApp__registerApps()
{
  MyMooseAppTestApp::registerApps();
}
