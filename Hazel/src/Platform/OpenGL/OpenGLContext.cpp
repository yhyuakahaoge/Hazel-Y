#include "hzpch.h"
#include "OpenGLContext.h"
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Hazel {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HZ_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Failed to initialize Glad!");


		HZ_CORE_INFO("OpenGL Info:");
		HZ_CORE_INFO("Vendor: {0}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
		HZ_CORE_INFO("Renderer: {0}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
		HZ_CORE_INFO("Version: {0}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));
		HZ_CORE_WARN("{0}", R"(
                             _ooOoo_					
                            o8888888o					
                            88" . "88					
                            (| -_- |)					
                            O\  =  /O					
                         ____/`---'\____				
                       .'  \\|     |//  `.				
                      /  \\|||  :  |||//  \				
                     /  _||||| -:- |||||-  \			
                     |   | \\\  -  /// |   |			
                     | \_|  ''\---/''  |   |			
                     \  .-\__  `-`  ___/-. /			
                   ___`. .'  /--.--\  `. . __			
                ."" '<  `.___\_<|>_/___.'  >'"".		
               | | :  `- \`.;`\ _ /`;.`/ - ` : | |		
               \  \ `-.   \_ __\ /__ _/   .-` /  /		
          ======`-.____`-.___\_____/___.-`____.-'======	
                             `=---='					
          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^	
                     佛祖保佑        永无BUG				
            佛曰:										  
                   写字楼里写字间，写字间里程序员；			
                   程序人员写程序，又拿程序换酒钱。			
                   酒醒只在网上坐，酒醉还来工位眠；			
                   酒醉酒醒日复日，上学放学年复年。			
                   但愿老死电脑间，不愿鞠躬权贵前；			
                   奔驰宝马富贵者，公交自行程序员。			
                   别人笑我忒疯癫，我笑自己命太贱；	
		)");
		/*HZ_CORE_WARN("{0}", R"(
        quu..__
         $$$b  `---.__
          "$$b        `--.                          ___.---uuudP
           `$$b           `.__.------.__     __.---'      $$$$"              .
             "$b          -'            `-.-'            $$$"              .'|
               ".                                       d$"             _.'  |
                 `.   /                              ..."             .'     |
                   `./                           ..::-'            _.'       |
                    /                         .:::-'            .-'         .'
                   :                          ::''\          _.'            |
                  .' .-.             .-.           `.      .'               |
                  : /'$$|           .@"$\           `.   .'              _.-'
                 .'|$u$$|          |$$,$$|           |  <            _.-'
                 | `:$$:'          :$$$$$:           `.  `.       .-'
                 :                  `"--'             |    `-.     \
                :##.       ==             .###.       `.      `.    `\
                |##:                      :###:        |        >     >
                |#'     `..'`..'          `###'        x:      /     /
                 \                                   xXX|     /    ./
                  \                                xXXX'|    /   ./
                  /`-.                                  `.  /   /
                 :    `-  ...........,                   | /  .'
                 |         ``:::::::'       .            |<    `.
                 |             ```          |           x| \ `.:``.
                 |                         .'    /'   xXX|  `:`M`M':.
                 |    |                    ;    /:' xXXX'|  -'MMMMM:'
                 `.  .'                   :    /:'       |-'MMMM.-'
                  |  |                   .'   /'        .'MMM.-'
                  `'`'                   :  ,'          |MMM<
                    |                     `'            |tbap\
                     \                                  :MM.-'
                      \                 |              .''
                       \.               `.            /
                        /     .:::::::.. :           /
                       |     .:::::::::::`.         /
                       |   .:::------------\       /
                      /   .''               >::'  /
                      `',:                 :    .'
                                           `:.:'  
		)");*/

		HZ_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Hazel requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}
