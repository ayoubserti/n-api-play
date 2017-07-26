#include <node_api.h>
#include <stdio.h>

napi_value  hello(napi_env env,  napi_callback_info info)
{

    napi_value result = nullptr;
    printf("Hello from Method\n"  );

    return result;

}

napi_value sum(napi_env env,  napi_callback_info info)
{
    size_t sizeArg = 2;
    napi_value argv[2],result;
    double val1, val2;

    /*
        retrieve callback info
    */
    napi_status status = napi_get_cb_info(env, info,&sizeArg,argv,nullptr,nullptr);

    if(status != napi_ok) return nullptr;

    if(sizeArg < 2){
        /*
            throw a JS exception
        */
        napi_throw_error(env,"sum needs 2 arguments.");
        return nullptr;
    }

    /*
        retrieve arguments as `double` values
    */
    if ( napi_get_value_double(env, argv[0],&val1) != napi_ok ) return nullptr;
    if ( napi_get_value_double(env, argv[1],&val2) != napi_ok) return nullptr;


    /*
        create the resulting napi_value
    */
    status = napi_create_number(env,val1+val2,&result);

    if(status == napi_ok) return result;
    return nullptr;
}




void Init(napi_env env, napi_value exports, napi_value module, void* priv) {
  napi_status status;
  napi_value fn,fun2;
  status =  napi_create_function(env, NULL, hello, NULL, &fn);
  if (status != napi_ok) return;
  status =  napi_create_function(env, NULL, sum, NULL, &fun2);
  if (status != napi_ok) return;

  //expose functions
  status = napi_set_named_property(env, exports, "hello", fn);
  if (status != napi_ok) return;

  status = napi_set_named_property(env, exports, "sum", fun2);
  if (status != napi_ok) return;

}




NAPI_MODULE(napi_play, Init)
