if (auto track = edit.getOrInsertAudioTrackAt(0))
{
  edit.getPluginCache().newPluginAddedCallback = [](const te::Plugin& p) {
    auto state = p.windowState.get();
    state->showWindowExplicitly();
  };

  auto plugin = edit.getPluginCache().createNewPlugin(te::ExternalPlugin::xmlTypeName, *desc).get();							
  track->pluginList.insertPlugin(*plugin, 0, nullptr);
}
