Pod::Spec.new do |s|
    s.name             = 'ASC_EXT'
    s.version          = '0.1.0'
    s.summary          = 'Alo7 Streaming Class External SDK'
    s.homepage         = 'https://github.com/alo7/asc-ios'
    s.license          = { :type => 'MIT', :file => 'LICENSE' }
    s.author           = { 'Dapeng Li' => 'dapeng.li@alo7.com' }
    s.source           = { :git => 'https://github.com/alo7/asc-ios.git', :tag => s.version.to_s }
  
    s.ios.deployment_target = '9.0'    
    s.dependency 'AliPlayerSDK_iOS', '4.7.4'
    s.dependency 'SingSoundSDK', '0.5.8'
    
    s.vendored_frameworks = 'Frameworks/ASC_EXT.framework'
    s.resource_bundle = { 'ASC_EXT' => 'Resources/Images.xcassets' }

    s.frameworks = 'CoreTelephony', 'AVFoundation'
    s.libraries = 'z', 'c++'
  end
