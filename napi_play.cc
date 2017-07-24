#include <node_api.h>
#include <stdio.h>

napi_value  hello(napi_env env,  napi_callback_info info)
{

    napi_value result = nullptr;
    printf("Hello from Method\n"  );

    return result;

}



void Init(napi_env env, napi_value exports, napi_value module, void* priv) {
  napi_status status;
  napi_value fn;
  status =  napi_create_function(env, NULL, hello, NULL, &fn);
  if (status != napi_ok) return;

  status = napi_set_named_property(env, exports, "hello", fn);
  if (status != napi_ok) return;

}




NAPI_MODULE(napi_play, Init)
